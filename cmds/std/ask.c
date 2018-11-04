// ask.c
// From ES2
// Modified by Xiang for XKX (12/15/95)

#include <ansi.h>
string query_inquiry(object ob);
inherit F_CLEAN_UP;

string *msg_dunno = ({
	"$nҡҡͷ��˵����û��˵����\n",
	"$n�ɻ�ؿ���$N��ҡ��ҡͷ��\n",
	"$n�����۾�����$N����Ȼ��֪��$P��˵ʲô��\n",
	"$n�����ʼ磬�ܱ�Ǹ��˵���޿ɷ�档\n",
	"$n˵������....���ҿɲ��������������ʱ��˰ɡ�\n",
	"$n����һ�����˵�����Բ������ʵ�����ʵ��û��ӡ��\n",
});

int main(object me, string arg)
{
	string dest, topic, msg;
	object ob;
	mapping inquiry;
        string str;


	seteuid(getuid());
			str=read_file("/log/NEWS");

        if( me->is_busy() )
                return notify_fail("����Ъ������˵���ɡ�\n");

	if( !arg || sscanf(arg, "%s about %s", dest, topic)!=2 )
		return notify_fail("��Ҫ��˭ʲô�£�\n");

	if( !objectp(ob = present(dest, environment(me))) )
		return notify_fail("����û������ˡ�\n");

	if( !ob->is_character() ) {
		message_vision("$N����$n��������....\n", me, ob);
		return 1;
	}

	if( !ob->query("can_speak") ) {
		message_vision("$N��$n�����йء�" + topic + "������Ϣ������$p��Ȼ�������˻���\n", me, ob);
		return 1;
	}

	if( !INQUIRY_D->parse_inquiry(me, ob, topic) )
		message_vision("$N��$n�����йء�" + topic + "������Ϣ��\n", me, ob);

	if( userp(ob) ) return 1;
	if( !living(ob) ) {
		message_vision("���Ǻ���Ȼ�ģ�$n���ڵ�״��û�а취��$N�κδ𸲡�\n",
			me, ob);
		return 1;
	}

	if( msg = ob->query("inquiry/" + topic) ) {
		if( stringp(msg) ) {
			message_vision( CYN "$N˵����" + msg + "\n" NOR, ob);
			return 1;
		}
	} else {
  	        if(ob->query("race")=="Ұ��") {
			message_vision("���Ǻܿ�ϧ��$N����˵����\n", ob);
			return 1;
		}
		switch(topic) {
			case "name":
			message_vision( CYN "$N˵�����ҵ����־���$N," + RANK_D->query_respect(me)+ "��ʲô��?\n" NOR, ob);
				break;
			case "here":
				message_vision(CYN "$n��$N˵����������" + environment(ob)->query("short") + "���������" + RANK_D->query_self(ob) + "Ҳ��̫�����\n" NOR, me, ob);
				break;
			case "rumors":
			message_vision( CYN "$N����˵��,���������˵��:"+str+"" NOR, ob);				break;
			default:
		if(topic=="news")
			{
                        if (!str)
			{
			message_vision( CYN "$N����˵��,���ûʲô���ſ�˵.." NOR, ob);
			}
else {
			message_vision( CYN "$N����˵��,���������˵��:"+str+"" NOR, ob);
}
			return 1;
		}	
		if(topic=="all")
			{
			message_vision( CYN "$N��������˵��:"+query_inquiry(ob)+"!\n" NOR, ob);
			return 1;
		}
				if (topic == ob->query("name") || ob->id(topic))
				message_vision(CYN "$n˵�����Ǿ���" + RANK_D->query_self_rude(ob) + "ѽ��\n" NOR, me, ob);
				else if (topic == me->query("name") || me->id(topic))
				message_vision(CYN "$n˵�����Ǿ���" + RANK_D->query_rude(me) + "��ѽ��\n" NOR, me, ob);
                                else if (topic == ob->query("name") || ob->id(topic))
				EMOTE_D->do_emote(ob, "name1");
else if (ob->query("combat_exp") < 500000)
{
                                if (strsrch(topic,"����")>= 0 || strsrch(topic,"����")>= 0)
                                message_vision(CYN "$n˵���������Ǿ���,��˵�����ǧ��¥����\n" NOR, me, ob);
                                else if (strsrch(topic,"����")>= 0 || strsrch(topic,"����")>= 0)
                                message_vision(CYN "$n˵�����˳Ʊ����Ĺ����������ɹųɼ�˼���Ľ���������
�����߹֡�ȫ�������ڵ���������ؤ�����߹��͡�����ͯ���ܲ�ͨ���˵�ͽ�ܣ���������书�\n" NOR, me, ob);
                                else if (strsrch(topic,"������")>= 0 || strsrch(topic,"����")>= 0)
                                message_vision(CYN "$n˵�������µ�һ�����ɾ������֡��\n" NOR, me, ob);
                                else if (strsrch(topic,"�䵱��")>= 0 || strsrch(topic,"�䵱")>= 0)
                                message_vision(CYN "$n˵�����䵱���������ҵ�ż�񡣡\n" NOR, me, ob);
                                else if (strsrch(topic,"�� ��")>= 0 || strsrch(topic,"����")>= 0)
                                message_vision(CYN "$n˵�������µ�һ�̣����˳�ħ�̵����̡��\n" NOR, me, ob);
                                else if (strsrch(topic,"��ɽ��")>= 0 || strsrch(topic,"��ɽ")>= 0)
                                message_vision(CYN "$n˵�������¾Ž��������µ�һ�����\n" NOR, me, ob);
                                else if (strsrch(topic,"����Ľ��")>= 0 || strsrch(topic,"Ľ��")>= 0)
                                message_vision(CYN "$n˵������ʲô������, ��Ҫʲô��������\n" NOR, me, ob);
                                else if (strsrch(topic,"�һ���")>= 0 || strsrch(topic,"�һ�")>= 0)
                                message_vision(CYN "$n˵�����һ����������书���ֶ����ɲ��١��\n" NOR, me, ob);
                                else if (strsrch(topic,"����μ�")>= 0 || strsrch(topic,"������")>= 0)
                                message_vision(CYN "$n˵���������񽣡��貨΢������ѧ�ĸ������أ��\n" NOR, me, ob);
                                else if (strsrch(topic,"ؤ��")>= 0 || strsrch(topic,"ؤ��")>= 0)
                                message_vision(CYN "$n˵�������µ�һ��ô����Ȼ��ؤ���ˡ��\n" NOR, me, ob);
                                else if (strsrch(topic,"��Ĺ")>= 0 || strsrch(topic,"��Ĺ��")>= 0)
                                message_vision(CYN "$n˵����������£�������ʣ���֪��Ĺһ�ɿ��д��ˣ��\n" NOR, me, ob);
                                else if (strsrch(topic,"������")>= 0 || strsrch(topic,"����")>= 0)
                                message_vision(CYN "$n˵�����������ͨ���ӣ��ڵ��������ٱ�����һ����.....�\n" NOR, me, ob);
                                else if (strsrch(topic,"������")>= 0 || strsrch(topic,"ѩɽ��")>= 0)
                                message_vision(CYN "$n˵������ѩɽ��������������ȥ�ܾ��ˣ��\n" NOR, me, ob);
                                else if (strsrch(topic,"������")>= 0 || strsrch(topic,"����")>= 0)
                                message_vision(CYN "$n˵���������ɶ����ö�����!���޳�֮ͽ�\n" NOR, me, ob);
                                else if (strsrch(topic,"���ư�")>= 0 || strsrch(topic,"����")>= 0)
                                message_vision(CYN "$n˵�����Ǻ�צɽ�������ɽ��,������������һ�㡣�\n" NOR, me, ob);
                                else if (strsrch(topic,"��ɽ��")>= 0 || strsrch(topic,"��������")>= 0)
                                message_vision(CYN "$n˵������˵�������ɾ�Ҫ�ϲ��ˡ��\n" NOR, me, ob);
                                else if (strsrch(topic,"������")>= 0 || strsrch(topic,"����")>= 0)
                                message_vision(CYN "$n˵��������ɽ��Сʦ���ǿ���Ư���ĺܰ����ٺ١��\n" NOR, me, ob);
                                else if (strsrch(topic,"���չ�")>= 0 || strsrch(topic,"����")>= 0)
                                message_vision(CYN "$n˵�������չ��Ͽɶ��Ǵ���Ů��һ������������Ůһ�����\n" NOR, me, ob);
                                else if (strsrch(topic,"����ɽׯ")>= 0 || strsrch(topic,"����")>= 0)
                                message_vision(CYN "$n˵������˵����ɽ���кܶ���,�ÿ��°����\n" NOR, me, ob);
                                else if (strsrch(topic,"��ң��")>= 0 || strsrch(topic,"��ң")>= 0)
                                message_vision(CYN "$n˵������ң�ɺ�������չ����˳����������\n" NOR, me, ob);
                                else if (strsrch(topic,"������")>= 0 || strsrch(topic,"����")>= 0)
                                message_vision(CYN "$n˵������������������䡣�ٽ�˫�����\n" NOR, me, ob);
                                else if (strsrch(topic,"������� ")>= 0 || strsrch(topic,"����")>= 0)
                                message_vision(CYN "$n˵�����ճ�������Ψ�Ҳ��ܡ��\n" NOR, me, ob);
                                else if (strsrch(topic,"������")>= 0 || strsrch(topic,"����")>= 0)
                                message_vision(CYN "$n˵������������������䡣�ٽ�˫�����\n" NOR, me, ob);
                                else if (strsrch(topic,"������")>= 0 || strsrch(topic,"����")>= 0)
                                message_vision(CYN "$n˵����һ�߽������ǵ��ˣ�����Ļ��������\n" NOR, me, ob);
                                else if (strsrch(topic,"�嶾��")>= 0 || strsrch(topic,"�嶾")>= 0)
                                message_vision(CYN "$n˵��������ÿ��£�ʲô���ﶼ�С��\n" NOR, me, ob);

}
				else
					message_vision(msg_dunno[random(sizeof(msg_dunno))], me, ob);
		}
	}
	return 1;
}

string query_inquiry(object ob)
{
	int i=0;
	mapping inq;
	string str="", *indexs;
	
	if(mapp(inq=ob->query("inquiry")))
		{
		indexs=keys(inq);
		for(i=0;i<sizeof(indexs);i++)
			{
				str=indexs[i]+" "+str;
				}
		str="�й��� "HIB+str+NOR CYN"������,�Һܸ��˸�����!";
		return str;
		}
	return "ʵ���ǶԲ���,��ʲôҲ��֪��ѽ!";
	}

int help(object me)
{
   write( @HELP
ָ���ʽ: ask <someone> about <something>

���ָ���ڽ���ʱ����Ҫ, ͨ��������ɴ�һָ�����
��ý�һ������Ѷ��
Ԥ���ѯ������:
	here
	name
	news
	all
HELP
   );
   return 1;
}
