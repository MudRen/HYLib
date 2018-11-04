// huqingyu.c
#include <ansi.h>
#include <command.h>
//inherit F_CLEAN_UP;
inherit NPC;

void create()
{
        set_name("������",({ "hu qingyu","hu" }));
        set("gender", "����" );
        set("age", 63);
        set("no_kill",1);
        set("no_fight",1);
        set_temp("no_kill",1);
        set("no_get",1);
        set("long",
"�������ǵ���һ����ҽ�����ı��������ޱȡ������������֮����\n");
        set("combat_exp", 200000);
        set("attitude", "friendly");
        set("inquiry", ([
            "����": "��˵��һ�����ƽ𣬿���죡",
            "��ʦ": "�����ݳǵ�����ɰɣ�",
            "����": "����۸���...!�ٺ�,һ��һ�����ƽ�����һ�ꡣ",
        ]) );
        set("chat_msg",({
            "���������Ŷ�����:Ҫ�뻽�����ǵ��ഺ,�ó���ĳ�����!!\n",
            "��������Ц��:Ҫ��ʦ? ���ס�����ó����������!\n",
            "�����൭��˵��:�ĸ���,���������ˡ�\n",
        }));
        setup();
}
void init()
{
        object ob,me;
        add_action("do_name","name");
        add_action("do_betrayer","betrayer");
        add_action("do_age","age");
}
int accept_object(object me, object ob)
{
        if( ob->query("money_id") && ob->value() >= 1000000)
        {
        command("nod");
        command("say �ðɣ�"+me->query("name")+"��˵���³̣�\n");
        me->set_temp("marks/huqingyu",1);
        return 1;
        }
}
int do_name(string arg,object me)
{
	string *banned_name = ({
		"��", "��", "��", "��", "��", "��", "��", "��", "��",
		"����ү", "������", "����", "ʱ��", "��",
		"����", "�����п�", "����", "���"
	});
	int i;

        me = this_player();
        if(!(int)me->query_temp("marks/huqingyu"))
        {
            return notify_fail("�����෭�źڰ��ۣ�Ǯ�أ�û��Ǯ��ռ���ˣ�\n");
        }
        if( !arg ) return notify_fail("������Ц���������ܸ�дȫ�ɡ�\n");
        if( strlen(arg) > 10 )
        return notify_fail("�����ྪ��������������ô�������֣�\n");
        if( strlen(arg) < 4 )
        return notify_fail("���������һ������ô����ɶ���֣�\n");
	while(i--) {
		if( arg[i]<=' ' ) {
			write("�Բ�������������ֲ����ÿ�����Ԫ��\n");
			return 0;
		}
		if( (strsrch(arg, "��") >= 0) ||
		    (strsrch(arg, "��") >= 0)) {
			write("�Բ�������������ֲ������������ĵ��֡�\n");
			return 0;
		}
		if( (strsrch(arg, "(") >= 0) ||
		    (strsrch(arg, "С����") >= 0)) {
			write("�Բ�������������ֲ������������ĵ��֡�\n");
			return 0;
		}
		if( (strsrch(arg, ")") >= 0) ||
		    (strsrch(arg, "С����") >= 0)) {
			write("�Բ�������������ֲ������������ĵ��֡�\n");
			return 0;
		}

		if( i%2==0 && !is_chinese(arg[i..<0]) ) {
			write("�Բ��������á����ġ�ȡ���֡�\n");
			return 0;
		}
	}
	if( member_array(arg, banned_name)!=-1 ) {
		write("�Բ����������ֻ���������˵����š�\n");
		return 0;
	}
	if( (strlen(arg) < 2) || (strlen(arg) > 10 ) ) {
		write("�Բ�������������ֱ����� 1 �� 5 �������֡�\n");
		return 0;
	}

        me->delete_temp("marks/huqingyu");
        if (me->query("gender")=="Ů��")
        message_vision(CYN"�������һ�Ӿ͸���$N�ķ��� !��ˬ����....\n"NOR,me);
        else
        message_vision(CYN"�������һ�Ӿ͸���$N�Ĵ���..����!!\n"NOR,me);
        me->set("name",arg);

        return 1;
}

int do_betrayer(object me)
{
        mapping my_skl;
        string *skl_name;
        int i,*level;
        me = this_player();
        if(!(int)me->query_temp("marks/huqingyu"))
        {
            return notify_fail("�����෭�źڰ��ۣ�Ǯ�أ�û��Ǯ��ռ���ˣ�\n");
        }

        me->delete_temp("marks/huqingyu");
        if (me->query("combat_exp")<10000)
            return notify_fail("��ԩ��!!��ľ��黹���������ʦ��! \n");

        my_skl=me->query_skills();
        if(mapp(my_skl)) {
        		skl_name = keys(my_skl);
        		level=values(my_skl);
        		for (i=0;i<sizeof(skl_name);i++)
{
if (level[i]>3)
        		me->set_skill(skl_name[i],level[i]-2);
}
if (me->query("max_neili")>200)
{
me->add("max_neili",-100);
}
                  }

        me->add("betrayer",1);
        me->set("title","��ͨ����");
        me->set("class","0");
        me->delete("family");
        me->delete("party");
    message_vision(CYN"�����Ц��: �����Ϻ������, ����$N�������! \n"NOR,me);

        return 1;
}

int do_age(object me)
{
        object obj;
        me = this_player();

        if(!(int)me->query_temp("marks/huqingyu"))
        {
            return notify_fail("�����෭�źڰ��ۣ�Ǯ�أ�û��Ǯ��ռ���ˣ�\n");
        }
//        me->delete_temp("marks/huqingyu");
//        return notify_fail("�����෭�źڰ��ۣ�������ʱ�Ͳ������ˣ�\n");

        if (me->query("age")<49)
        {
            return notify_fail("������: �㻹�������ϰ�ʮ��, ��һ�����ƽ�׻���! \n");
        }

        if (me->query("mud_age")<864000)
        {
            return notify_fail("������: �㻹�������, ��һ�����ƽ�׻���! \n");
        }

        me->delete("last_alert");
        me->delete_temp("marks/huqingyu");
          me->add("mud_age",-86400);
          me->add("age",-1);
        message_vision(CYN"������: ��Ȼ��Ǯ��ʹ����ĥ, $N���ڿ����������! \n"NOR,me);

        return 1;
}