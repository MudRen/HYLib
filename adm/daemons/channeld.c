// channeld.c 
// 97-10-18 add intermud channel and emote capability
//      By ken@XAJH & fuyo@XAJH 

#include <ansi.h>
#include <mudlib.h>
#include <net/dns.h>
#include <net/macros.h>

inherit F_DBASE;

#define BLOCK_CHAT      0
#define BLOCK_RUMOR     0
#define REMOTE_Q    "/adm/daemons/network/services/remote_q.c"

string remove_addresses(string, int all);

mapping channels = ([

    "sys":  ([  "msg_speak": HIR "��ϵͳ��%s��%s\n" NOR,
            "msg_color": NOR+HIR,
            "wiz_only": 1,
        ]),

    "adm":  ([  "msg_speak": HIW "%s: %s\n" NOR,
            "msg_emote": NOR+HIW+"������ʦ��%s" NOR,
            "msg_color": NOR+HIW,
            "arch_only": 1,
        ]),

    "wiz":  ([  "msg_speak": NOR+HIY+"����ʦ��"+HIY+"%s��%s\n" NOR,
            "msg_emote": NOR+HIY+"����ʦ��"+HIY+"%s" NOR,
            "intermud": GCHANNEL,
            "intermud_emote": 1,
            "msg_color": NOR+HIY,           
            "wiz_only": 1,
            "channel": "hywiz",
            "omit_address": 0,
          "filter": 1,
	]),
    "asd": ([  "msg_speak": NOR+HIC+"�����羯�졿"+HIY+"%s��%s\n" NOR,
            "msg_emote": NOR+HIC+"�����羯�졿"+HIY+"%s" NOR,
            "eschat_only": 1,
            "intermud": GCHANNEL,
            "intermud_emote": 1,
            "channel": "asd",
            "msg_color": NOR+HIY,
            "filter": 1,
            "omit_address": 0, 
        ]),
    "gwiz": ([  "msg_speak": NOR+HIC+"��������ʦ��"+HIY+"%s��%s\n" NOR,
            "msg_emote": NOR+HIC+"��������ʦ��"+HIY+"%s" NOR,
            "eschat_only": 1,
             "msg_color": NOR+HIY,
            "filter": 1,
            "omit_address": 0, 
        ]),
    "yqyl": ([  "msg_speak": NOR+HIC+"���������䡿"+HIW+"%s��%s\n" NOR,
            "msg_emote": NOR+HIC+"���������䡿"+HIW+"%s" NOR,
            "intermud": GCHANNEL,
            "intermud_emote": 1,
            "channel": "yqyl",
            "msg_color": NOR+HIY,
            "filter": 1,
            "omit_address": 0, 
        ]),
    "hy": ([  "msg_speak": NOR+HIC+"������II��"+HIW+"%s��%s\n" NOR,
            "msg_emote": NOR+HIC+"������II��"+HIW+"%s" NOR,
            "intermud": GCHANNEL,
            "intermud_emote": 1,
            "channel": "hy",
            "msg_color": NOR+HIY,
            "filter": 1,
            "omit_address": 0, 
        ]),
	"auction":([	"msg_speak": HIY "����������%s: %s\n" NOR,
			"msg_color": HIY,
		]),
    "gwiz": ([  "msg_speak": NOR+HIC+"��������ʦ��"+HIY+"%s��%s\n" NOR,
            "msg_emote": NOR+HIC+"��������ʦ��"+HIY+"%s" NOR,
            "eschat_only": 1,
            "intermud": GCHANNEL,
            "intermud_emote": 1,
            "channel": "gwiz",
            "msg_color": NOR+HIY,
            "filter": 1,
            "omit_address": 0, 
        ]),
    "gbwiz":([      
        	"msg_speak": BOLD "����½��ʦ��%s��%s\n" NOR,
            "msg_emote": BOLD "����½��ʦ��%s" NOR,
            "msg_color": BOLD,
            "intermud": GCHANNEL,
            "intermud_emote": 1, 
            "channel": "gbwiz",
            "eschat_only": 1,
            "omit_address": 0, 
            "filter": (: $1["ENCODING"] == MUDLIB_ENCODING :)
                ]),
    "debug":([  "msg_speak": HIW "�����ԡ�%s��%s\n" NOR,
            "msg_emote": HIY "�����ԡ�%s" NOR,
            "msg_color":HIW,
            "wiz_only": 1,
        ]),

    "chat": ([  "msg_speak": HIC+"���۵�������%s��%s\n" NOR,
            "msg_emote": HIC+"���۵�������"+CYN+"%s" NOR,
            "msg_color": NOR+HIC,
        ]),        

    "rumor":    ([  "msg_speak": HIM "������ҥ�ԡ�%s��%s\n" NOR,
            "msg_emote": HIM "������ҥ�ԡ�%s" NOR,
            "msg_color": NOR+HIR,
            "anonymous": "ĳ��",
        ]),

    "party":([  "msg_speak": HIG "��%s��%s: %s\n" NOR,
            "msg_emote": HIG "��%s��%s" NOR,
            "msg_color": NOR+HIG,
        ]),

    "es":   ([  "msg_speak": NOR+BOLD+"���������ġ�"+NOR+BOLD+"%s��%s\n" NOR,
            "msg_emote": NOR+BOLD+"���������ġ�"+NOR+BOLD+"%s" NOR,
            "msg_color": NOR+BOLD,
            "intermud": GCHANNEL,
            "intermud_emote": 1,
            "eschat_only": 1,
            "channel": "es",
            "filter": 1,
            "omit_address": 0, 
        ]),

]);

void create()
{
    // This is required to pass intermud access check.
    seteuid(getuid());
    set("channel_id", "Ƶ������");
}


varargs int do_channel(object me, string verb, string arg, int emote,int remote)
{
    object *ob;
    string *tuned_ch, who;
    string arg_bk,self_emote;
    mixed *value,*index;
    int i,j;
    self_emote=arg;

    // Check if this is a channel emote.
    if( sizeof(verb) > 2 ) {
        if( verb[sizeof(verb)-1] == '*' ) {
            emote = 1;
            verb = verb[0..<2];
            }
    }


    // Check if this is a channel messsage.
    if( !mapp(channels) || undefinedp(channels[verb]) ) return 0;

    // check if this channel support emote message. 
    if( emote && undefinedp(channels[verb]["msg_emote"])  ) {
        write("�Բ������Ƶ����֧�� emote ��\n");
        return 1;
    }
    //now we can be sure it's indeed a channel message:
    if (!stringp(arg) || arg == "" || arg == " ") arg = "...";
    else arg_bk = arg;
    
    if(remote) arg_bk = arg;

    // check if one can write to channels
    // only block rumor or chat...
    if (!me) return 0;
if(!userp(me) && me->query("id")=="ma fu")
{	
return 0;
}
        if ( ((int)time() - (int)me->query_temp("chat_times")) < 1 
        && userp(me))
		return notify_fail("�л��ú�˵����Ҫ��ô���\n");
if ( strlen(arg)>500)
return notify_fail("��˵��ô�໰��ʲô! ��ˢ��? \n");

	if ( userp(me) && !wizardp(me))
	{
		if(me->query_condition("killer"))
		return notify_fail("�����ڱ�ͨ���У�����ʹ�ù���Ƶ����\n");

/*
        if ( ((int)time() - (int)me->query_temp("chat_times") < 5) &&  strlen(arg)>80)
{
		if(me->query("combat_exp") < 5000)
		return notify_fail("ֻ�о������5000,����������ʹ�ù���Ƶ����\n
		������ֻ��5������һ�Σ������(help xipanzi) ϴ��������0-5000������\n");
		if(me->query("combat_exp") > 299999 && me->query("combat_exp") < 305000)
		return notify_fail("ֻ�о������305000,����������ʹ�ù���Ƶ����\n
		������ֻ��5������һ�Σ������(help xipanzi) ϴ��������0-5000������\n");

}

		if(me->query("combat_exp") < 5000)
{
if ( strlen(arg)>80)
return notify_fail("��˵��ô�໰��ʲô! ��ˢ��? ֻ�о������5000,����������ʹ�ù���Ƶ����\n");
		if(me->query("combat_exp") > 299999 && me->query("combat_exp") < 305000
		&& strlen(arg)>80)
return notify_fail("��˵��ô�໰��ʲô! ��ˢ��? ֻ�о������5000,����������ʹ�ù���Ƶ����\n");
}
*/
		if(time()-(int)me->query("chblk_channel/all")<3600)
			return notify_fail("�����е�����Ƶ�������ر��ˣ�\n");
		switch (verb)
		{
			case "rumor" : if (time() - (int)me->query("chblk_channel/rumor") < 3600)
				return notify_fail("���ҥ��Ƶ�����ر��ˣ�\n");
				break;
			case "chat"  : if (time() - (int)me->query("chblk_channel/chat") < 3600)
				return notify_fail("�������Ƶ�����ر��ˣ�\n");
				break;
			case "party" : if (time() - (int)me->query("chblk_channel/party") < 3600)
				return notify_fail("�������Ƶ�����ر��ˣ�\n");
				break;
			case "es"    : if (time() - (int)me->query("chblk_channel/es") < 3600)
 				return notify_fail("�����������Ƶ�����ر��ˣ�\n");
				break;
			case "sing"    : if (time() - (int)me->query("chblk_channel/sing") < 3600)
 				return notify_fail("��ĸ質Ƶ�����ر��ˣ�\n");
				break;
			case "new"    : if (time() - (int)me->query("chblk_channel/new") < 3600)
				return notify_fail("�����������Ƶ�����ر��ˣ�\n");
			case "yqyl"    : if (time() - (int)me->query("chblk_channel/yqyl") < 3600)
				return notify_fail("�����������Ƶ�����ر��ˣ�\n");
			case "hy"      : if (time() - (int)me->query("chblk_channel/hy") < 3600)
				return notify_fail("��ĺ���Ƶ�����ر��ˣ�\n");
				break;
                }
	}
                me->set_temp("chat_times",time());
        if( userp(me) ) {
        if( channels[verb]["wiz_only"] && !wizardp(me))
        return 0;
        if( channels[verb]["eschat_only"] && !wizardp(me))
        return 0;
        if( channels[verb]["arch_only"] && wiz_level(me)<wiz_level("(arch)"))
        return 0;

    // check if same channel message but not wizard
	if (strsrch(arg, "\n�۵�����") > 0)
		return notify_fail("��׼α��������Ϣ��\n");
	if (strsrch(arg, "\n����ҥ��") > 0)
		return notify_fail("��׼α��������Ϣ��\n");
	if (strsrch(arg, "\n����") > 0)
		return notify_fail("��׼α��������Ϣ��\n");
	if (strsrch(arg, "\nҥ��") > 0)
		return notify_fail("��׼α��ҥ����Ϣ��\n");
    if( !wizardp(me))
        if( arg==(string)me->query_temp("last_channel_msg") )
    return notify_fail("�ý�̸Ƶ��˵���벻Ҫ�ظ���ͬ��ѶϢ��\n");

    if( userp(me) && !wizardp(me)) {
        me->set_temp("last_channel_msg", arg);
        me->add_temp("channel_msg_cnt", 1);
       if (me->query_temp("channel_msg_cnt")>5)
            if (time()-me->query_temp("chat_time")<2){
                me->set("chblk_channel/"+verb,time());
                do_channel( this_object(), "rumor", sprintf("��������ó�һ�Ź�Ƥ��ҩ����С��¯��ϸϸ�������Ժ󣬡�ž������ס��%s����͡�\n", me->name(1) ));
                return 1;
            }else{
                me->set_temp("chat_time",time());
                me->delete_temp("channel_msg_cnt");
            }
    }

    // If we speaks something in this channel, then must tune it in.
    tuned_ch = me->query("channels");
    if( !pointerp(tuned_ch) )
        me->set("channels", ({ verb }) );
    else if( member_array(verb, tuned_ch)==-1 )
    me->set("channels", tuned_ch + ({ verb }) );
    }

    // Support of channel emote
    if( emote  && me->is_character() && !remote) {
        string vb, emote_arg, id, mud;

        if( sscanf(arg, "%s %s", vb, emote_arg)!= 2 ) {
            vb = arg;
            emote_arg = "";
            }

        if( channels[verb]["intermud_emote"]
            && sscanf(emote_arg, "%s@%s", id, mud)==2 ) {
                REMOTE_Q->send_remote_q(mud, verb, me->query("id"), id, vb);
                write("��·ѶϢ���ͳ������Ժ�\n");
                return 1;
           }

        if( channels[verb]["intermud_emote"] )
            arg = EMOTE_D->do_emote(me, vb, emote_arg, 3);
        else if( verb == "rumor*" && random(10)<7 && !wizardp(me))
            arg = EMOTE_D->do_emote(me, vb, emote_arg, 2, channels[verb]["anonymous"]);
        else if( verb == "rumor" && random(10)<7 && !wizardp(me))
            arg = EMOTE_D->do_emote(me, vb, emote_arg, 2, channels[verb]["anonymous"]);
        else    arg = EMOTE_D->do_emote(me, vb, emote_arg, 1);

        if (!arg && emote) {
        // we should only allow chinese emote.
        if( (int)vb[0] < 160 ) return 0;
			foreach (int item in vb) {
				if (item == ' ') break;
				if (item == '(')
					return notify_fail("��׼α�콻̸��Ϣ��\n");
				if (item == ')')
					return notify_fail("��׼α�콻̸��Ϣ��\n");
			}
            arg = sprintf("%s(%s@%s)%s\n",me->name(),me->query("id"),Mud_name(),arg_bk);
            if( verb == "rumor" ) {
                if( userp(me) )
                    arg = sprintf("%s%s\n",channels[verb]["anonymous"],vb);
            }
        }
    if( !arg ) {
        if( channels[verb]["anonymous"] ) 
            arg = channels[verb]["anonymous"]+vb+" "+emote_arg+"\n"; 
        else if( channels[verb]["intermud_emote"] )
            arg = sprintf("%s(%s@%s)%s %s\n", me->name(1),
                capitalize(me->query("id")), INTERMUD_MUD_NAME, vb, emote_arg);
        else    arg = me->name()+vb+" "+emote_arg+"\n"; 
        }
    }

    
    // Make the identity of speaker.
    if( channels[verb]["anonymous"] ) {
        who = channels[verb]["anonymous"];
        if (userp(me))
         if (random(10)>8 && !wizardp(me)) who=me->name(1) + "(" + capitalize(me->query("id")) + ")";
         else
                do_channel( this_object(), "sys", sprintf("%s����������ҥ��", me->name(1)));
    }
    else 

    if(me && (userp(me) || !stringp(who = me->query("channel_id")) ))
    {
        if (me->name()!=me->name(1) && emote)
                do_channel( this_object(), "sys", sprintf(HIW"%s(%s)"+WHT+"��%s!", me->name(1),me->query("id"),me->name()));
        who = me->name(1) + "(" + capitalize(me->query("id")) + ")";
    }

    if( verb == "adm" ) {
        who = sprintf("%s", RANK_D->query_rank(me));
        who = replace_string(who," ","");
        who = replace_string(who,NOR,"");
        who +=(me->name(1)+"("+capitalize(me->query("id"))+")");
    }


    // Ok, now send the message to those people listening us.
        if (verb=="party"){
                if (!me->query("family/family_name"))
                        return notify_fail(YEL"�㻹û�м����κ����ɣ�\n"NOR); 
                ob=filter_array( users(), "family_listener", this_object(), me->query("family/family_name") );
        }else
                ob = filter_array( users(), "filter_listener", this_object(), channels[verb] );


    if( !arg || arg == "" || arg == " " ) arg = "...";

    if( emote ) {
        string localmsg;
        string ecol=channels[verb]["msg_color"];
        if(remote) {
            arg=arg_bk;
        }

        if (!stringp(arg)) return 0;

        localmsg = arg;

        if ( channels[verb]["msg_emote"] )
            localmsg = remove_addresses(arg, 0); // 98-1-22 14:30

        if( channels[verb]["omit_address"] ) localmsg = remove_addresses(arg, 1);
        else if( channels[verb]["intermud_emote"] ) localmsg = remove_addresses(arg, 0);

        if(!stringp(localmsg)) return 0;
            if (verb=="party")
                message( "channel:" + verb,sprintf( channels[verb]["msg_emote"],me->query("family/family_name"), replace_string(localmsg,NOR,ecol) ), ob );
            else
                message( "channel:" + verb,  sprintf( channels[verb]["msg_emote"],replace_string(localmsg,NOR,ecol)), ob );
            }
        else
        if (verb=="party")
            message( "channel:" + verb,sprintf( channels[verb]["msg_speak"],me->query("family/family_name"),who,arg ), ob );
        else
            message( "channel:" + verb, sprintf( channels[verb]["msg_speak"], who, arg ), ob );

    if( arrayp(channels[verb]["extra_listener"]) ) {
        channels[verb]["extra_listener"] -= ({ 0 });
        if( sizeof(channels[verb]["extra_listener"]) )
            channels[verb]["extra_listener"]->relay_channel(me, verb, arg);
        }
        
    if( !undefinedp(channels[verb]["intermud"]) && me->is_character()) {
        channels[verb]["intermud"]->send_msg(
        channels[verb]["channel"], me->query("id"), me->name(1), arg, emote,
        channels[verb]["filter"] );
    }
     if(verb != "adm" 
  	  && verb != "debug" 
  	  && verb != "sys" 
  	  && verb != "wiz" 
  	  && verb != "snp" 
  	  && verb != "gbwiz"   //�������һЩ�����Ƶ�����ε�,���ݾ�������޸�
  	  && verb != "gwiz")  
//     if(verb = "chat" 
//  	  || verb = "rumor" 
//  	  || verb = "sys" 
//  	  || verb = "party" 
//  	  || verb = "hy" 
//  	  || verb = "yqyl")   //�������һЩ�����Ƶ�����ε�,���ݾ�������޸�
      write_file("/log/NEWS", arg+"\n", 1); //дһ��log��Ҫ��ask npc about news ʱ�õ�


    return 1;
}

int filter_listener(object ppl, mapping ch)
{
    // Don't bother those in the login limbo.
    if( !environment(ppl) ) return 0;

    if( ch["arch_only"])
        if( userp(ppl) )
            if( wiz_level(ppl) < wiz_level("(arch)") )
                return 0;

    if( ch["wiz_only"] ) 
        if( userp(ppl) )    
            return wizardp(ppl);

    if( ch["eschat_only"] ) 
        return 0;

    if( ch["es_only"] ) {
        if( wiz_level(ppl) > 0 ) return 1;
        if( ppl->query("age") > 23 ) return 1;
        return 0;
    }

    return 1;
}

void register_relay_channel(string channel)
{
    object ob;
    ob = previous_object();
    if( undefinedp(channels[channel]) || !ob) return;
    if( arrayp(channels[channel]["extra_listener"]) ) {
    if( member_array(ob, channels[channel]["extra_listener"]) >=0 ) return;
    channels[channel]["extra_listener"] += ({ ob });
    }
    else  channels[channel]["extra_listener"] = ({ ob });
}

string remove_addresses(string msg, int all)
{
    int i;
    mixed tmp;
    string pattern;

    if(!stringp(msg)) return msg;
    if( all )
        pattern = "[(][A-Za-z]+@[a-zA-Z]+[0-9]+[.]?[)]";
    else
        pattern = "[(][A-Za-z]+@"+Mud_name()+"[)]";

    tmp = reg_assoc(msg, ({pattern}), ({1}));

    if(!arrayp(tmp)) return msg;
    msg = "";
    for(i=0; i< sizeof(tmp[0]); i++)
        if( tmp[1][i] == 0 ) msg += tmp[0][i];
    return msg;
}
int family_listener(object ppl, string str)
{
        // Don't bother those in the login limbo.
        if( !environment(ppl)) return 0;
        
        if(wizardp(ppl) || ppl->query("family/family_name")==str ) return 1;
        else return 0;
}
