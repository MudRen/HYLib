// yuzu.c
// cgm 28/12/1999
// idea 7/4/2000

#include <ansi.h>

inherit NPC;

string *msg_d = ({
                      "�����","�����","ɵB","�Ҳ�","����","������˯",
                      "�٣�","��!","fuck","FUCK","Fuck","���",
                      "�����̵�","����������","�����","��үү��",
                      "�������ƨ","tmd","TMD","tmmd","TMMD","������","������","������",
                      "�����","��ƨwiz","��wiz","��wiz","������",
                      "������","�����","������","�ƣգã�","F u c k"
                      ,"f u c k","�����","�����","ɵB","�Ҳ�","����","������˯",
                      "ta nai nai de","tanainaide","tanai naide","ta nainai de","tanainai de","nnd",
                      "�٣�","��!","fuck","FUCK","Fuck","���",
                      "t nn d","tnnnnd","tnn d","t nnd","t n n d","tn nd","t.m.d"
                      "�����̵�","����������","�����","��үү��","t.n.n.d","tnnd"
                      "Сƨ��",
                      "�������ƨ","tmd","TMD","tmmd","TMMD","������","������","������",
                      "�����","��ƨwiz","��wiz","��wiz","������","tnnd","TNND","�����̵�",
                      "����","��wiz","���","����","������","������","ǿ��","����",
                      "�����","���","����",
                      });

string *msg_s = ({
                      "0","1","2","3","4","5",
                      "6","7","8","9"
                      });


void create()
{
        set_name("����", ({"yu zu","yuzu"}));
        set("title", HIY"�������Ÿ��֡�"NOR);
        set("gender", "����" );
        set("age", 30);
        set("per", 5);
        set("long", HIR"һ�����ص����䣬��������׼�������ʲô���¡�\n"NOR);
        set("combat_exp", 10000000);
        set("attitude", "peaceful");
        set("dex", 50);
        set("str", 50);
   
        set_skill("literate", 800);
        set("max_qi", 1000);
        set("max_jing", 500);
        set("max_neili", 1000);
  	
  	set("no_clean_up",1);
        setup();

        carry_object("/clone/misc/cloth")->wear();
        carry_object("/d/city/obj/gangjian")->wield();

	if( !clonep() ) CHANNEL_D->register_relay_channel("rumor");
	if( !clonep() ) CHANNEL_D->register_relay_channel("chat");
	if( !clonep() ) CHANNEL_D->register_relay_channel("party");
        if( !clonep() ) CHANNEL_D->register_relay_channel("es");
        if( !clonep() ) CHANNEL_D->register_relay_channel("sing");
        if( !clonep() ) CHANNEL_D->register_relay_channel("hy");
        if( !clonep() ) CHANNEL_D->register_relay_channel("auction");
        if( !clonep() ) CHANNEL_D->register_relay_channel("yqyl");

}

void relay_channel(object criminal, string channel, string msg)
{

        int i;
        string criname,result,ia,ib,ic,id;
        int howlong;
        if( !userp(criminal) ) return;

        for(i=0; i<sizeof(msg_d); i++)
        {
            if( !wizardp(criminal) && strsrch(msg, msg_d[i]) >= 0)
                   {
                    message_vision(CYN"�����Ÿ��ֺ�Ȼ���֣��ӳ����ף�һ�¾���ס$N�Ĳ��ӡ�\n$N�쳤��ͷ�����Ű��۵ر������ˡ�\n"NOR, criminal);
                    
                    criname = criminal->query("name") + "("+criminal->query("id")+")";
                    howlong=10;
                    
                    result = sprintf("%s��%sƵ��˵�໰(%s)�������� %d ��\n",
                    criname,channel,msg,howlong);
                    criminal->start_busy(50);
                    criminal->set_temp("disable_inputs",1);
	            call_out("recoveralias", 120);
                    
                    message("channel:rumor",HIM"��ҥ�ԡ�ĳ�ˣ���˵"+criname+"�ڹ���Ƶ��ʹ�ô����������ֹʹ��ָ���ˡ�\n"NOR, users());
                    return;
                    }
        }
/*if (criminal->query("combat_exp") < 500 && strsrch(msg,"0")>=0 || strsrch(msg,"1")>=0 || strsrch(msg,"2")>=0 || strsrch(msg,"3")>=0
|| strsrch(msg,"4")>=0 || strsrch(msg,"5")>=0 || strsrch(msg,"6")>=0 || strsrch(msg,"7")>=0 
|| strsrch(msg,"8")>=0 || strsrch(msg,"9")>=0 )
{
        if( strlen(msg)>=10
         && !wizardp(criminal)
         && criminal->query("combat_exp") < 800 )
{
                    criminal->start_busy(50);
                    criminal->set_temp("disable_inputs",1);
	            call_out("recoveralias", 120);
message_vision(CYN"�ù���Ƶ�������,̫û������!��$N��ָ�������!��\n$N�쳤��ͷ�����Ű��۵ر������ˡ�\n"NOR, criminal);
}
}
if (strsrch(msg,"0")>=0 || strsrch(msg,"1")>=0 || strsrch(msg,"2")>=0 || strsrch(msg,"3")>=0
|| strsrch(msg,"4")>=0 || strsrch(msg,"5")>=0 || strsrch(msg,"6")>=0 || strsrch(msg,"7")>=0 
|| strsrch(msg,"8")>=0 || strsrch(msg,"9")>=0 )
{
 	if( !wizardp(criminal) && sscanf( msg, "%s.%s.%s.%s",ia,ib,ic,id) && strlen(ia)>=1  && strlen(ib)>=1
 	 && strlen(ic)>=1 && strlen(id)>=1 && strlen(msg)>=10)
{
                    message_vision(CYN"�ù���Ƶ�������,̫û������!��$N��ָ�������!��\n$N�쳤��ͷ�����Ű��۵ر������ˡ�\n"NOR, criminal);
                    criminal->start_busy(50);
                    criminal->set_temp("disable_inputs",1);
	            call_out("recoveralias", 120);
}

}
*/
}

void recoveralias()
{
        this_object()->set_temp("disable_inputs",0);
        this_player()->set_temp("disable_inputs",0);
     message("system", HIG "\n������ϵͳ�ָ������ָ��....\n\n" NOR,
		this_object());
     message("system", HIG "\n������ϵͳ�ָ������ָ��....\n\n" NOR,
		this_player());

}
