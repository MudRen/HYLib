#include <ansi.h>
inherit ITEM;
void to_rob();
void create()
{
        set_name(HIR"�����ż�"NOR, ({"xin", "letter"}));
        set("long",
               "���Ǵ���μ��и������Ҫ�ż���\n");
        set("unit", "��");
        set("weight", 5);
//      set("no_drop", 1);
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
string targ;
int exp,pot;
        if (!arg||!ob=present(arg,environment(me)))
                return notify_fail("��Ҫ�����͸�˭��\n");
        targ=ob->query("name");
if ( targ != me->query("quest/quest") ) return notify_fail("�����͸�"+me->query("quest/quest")+"���ţ�����ô������Ҹ��أ�\n");
        if (userp(ob)) return notify_fail("��Ū�����˰ɣ�\n"); //��ҿ�������ͬ��NPC������
        if ( (int) me->query("task_time") < time() )
        {
             return notify_fail(targ+"�����˵������������,�������ҵĴ��£��㻹���������ң���\n");
        }
        tell_object(me,"����Ž�����"+targ+"��\n" NOR );
        exp=me->query("quest/exp_bonus");
        pot=me->query("quest/pot_bonus");
        tell_object(me,HIW""+targ+"��ϲ������л����ʱ���Ÿ��ң��㱻�����ˣ�\n"
        +chinese_number(exp)+"�㾭��ֵ��\n"
        +chinese_number(pot)+"��Ǳ�ܡ�\n\n"NOR);
        me->add("combat_exp",exp);
        me->add("potential",pot);
        me->set_temp("tufei",0);
        me->set("quest",0);
        destruct(present("xin",me));
        return 1;
}

void go()
{	
  if (random(100)<15&& !environment(this_object())->query("no_fight") )
	{	
        if (this_object()->query_temp("tufei")<3)
	{
		to_rob();
		this_object()->add_temp("tufei",1);
		call_out("go",30);}
		return;
	}call_out("go",10);
}

void to_rob()
{
	int i;
	int maxexp;
	object robber;
	object me=this_player();
	maxexp=me->query("combat_exp");
	message_vision(HIR"��Ȼ������һȺ�ٷˣ�\n"NOR,this_object());
	for (i=0;i<=random(2)+1;i++)
	{
		robber=new(__DIR__"tufei");
		robber->move(environment(this_player()));
		robber->set_leader(this_player());
                robber->set("combat_exp",maxexp);
		 if(objectp(present("biaoshi", environment(this_player()))))
		{	robber->kill_ob(present("biaoshi",environment(this_player())));
			present("biaoshi",environment(this_player()))->kill_ob(robber);}
		robber->kill_ob(this_player());
		this_player()->kill_ob(robber);
	}
	
}

void owner_is_killed() { destruct(this_object()); }
