#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIR"����"NOR, ({"huo wu", "huo wu"}));
        set("long",
               "���ǳ��ϰ�Ҫ���͵Ļ��\n");
        set("unit", "��");
        set("weight", 200);
        set("no_steal",1);
        set("no_beg", 1);
        set("no_put",1);
        set("no_drop", 1);
        set("no_get", 1);

        setup();
}

void init()
{
        add_action("do_sendto","sendto");
	remove_call_out("go");
	call_out("go",3);	
}

int do_sendto(string arg)
{
object ob=this_object(),me=this_player();
object obn;
int i;
string targ;
int exp,pot;
        if (!arg||!ob=present(arg,environment(me)))
                return notify_fail("��Ҫ�ѻ����͸�˭��\n");
        targ=ob->query("name");
if ( targ != me->query("quest/quest") ) return notify_fail("�����͸�"+me->query("quest/quest")+"�Ļ������ô������Ҹ��أ�\n");
        if (userp(ob)) return notify_fail("��Ū�����˰ɣ�\n"); //��ҿ�������ͬ��NPC������
        if ( (int) me->query("task_time") < time() )
        {
             return notify_fail(targ+"�����˵������������,�����ҵĴ��£���\n");
        }
        tell_object(me,"��ѻ��ｻ����"+targ+"��\n" NOR );
        exp=me->query("quest/exp_bonus");
        pot=me->query("quest/pot_bonus");
        tell_object(me,HIW""+targ+"��ϲ������л����ʱ�ͻ�����ң��㱻�����ˣ�\n"        +chinese_number(exp)+"�㾭��ֵ��\n"
        +chinese_number(pot)+"��Ǳ�ܡ�\n\n"NOR);
        me->add("combat_exp",exp);
        me->add("potential",pot);
        me->set("quest",0);
                   me->set_temp("menpaijob",0);
                   me->delete_temp("menpaijob");
        me->delete("tzjob");
	destruct(this_object());
//        destruct(present("huo wo",me));
        return 1;
}
void owner_is_killed() { destruct(this_object()); }

