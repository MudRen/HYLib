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
        set("no_drop", 1);
        set("no_get", 1);

        setup();
}

void init()
{
        add_action("do_sendto","sendto");
	remove_call_out("go");
	call_out("go",0);	
}

int do_sendto(string arg)
{
object ob=this_object(),me=this_player();
string targ;
int exp,pot;
int i;
        if (!arg||!ob=present(arg,environment(me)))
                return notify_fail("��Ҫ�����͸�˭��\n");
        targ=ob->query("name");
if ( targ != me->query("quest/quest") ) return notify_fail("�����͸�"+me->query("quest/quest")+"���ţ�����ô������Ҹ��أ�\n");
        if (userp(ob)) return notify_fail("��Ū�����˰ɣ�\n"); //��ҿ�������ͬ��NPC������
    if(me->is_busy())
        return notify_fail("��������æ��\n");
     if (me->is_fighting()) 
        return notify_fail("���������������!\n");

  if (random(100)<30&& !environment(this_player())->query("no_fight") )
	{	
        if (this_object()->query_temp("tufei")<1 && !environment(this_player())->query("no_fight")
         && !this_player()->is_fighting())
	{
		to_rob();
		this_object()->add_temp("tufei",1);
                this_player()->start_busy(1);
	}
		return 1;
	}

        if ( (int) me->query("task_time") < time() )
        {
             return notify_fail(targ+"�����˵������������,�������ҵĴ��£��㻹���������ң���\n");
        }
        tell_object(me,"����Ž�����"+targ+"��\n" NOR );
        exp=me->query("quest/exp_bonus");
        pot=me->query("quest/pot_bonus");
i=this_object()->query_temp("tufei");
if (i>0)
{
        exp=me->query("quest/exp_bonus")+60+i*60;
        pot=me->query("quest/pot_bonus")+40+i*40;
}
if (exp > 600) exp=600;
if (pot > 400) pot=400;
        tell_object(me,HIW""+targ+"��ϲ������л����ʱ���Ÿ��ң��㱻�����ˣ�\n"
        +chinese_number(exp)+"�㾭��ֵ��\n"
        +chinese_number(pot)+"��Ǳ�ܡ�\n\n"NOR);
        me->add("combat_exp",exp);
        me->add("potential",pot);
        me->set_temp("tufei",0);
        me->set("quest",0);
//        destruct(present("xin",me));
        destruct(this_object());
        return 1;
}

void go()
{	
if (this_player())
{
	this_player()->start_busy(1);
  if (random(100)<8&& !environment(this_player())->query("no_fight") )
	{	
        if (this_object()->query_temp("tufei")<2 && !environment(this_player())->query("no_fight")
         && !this_player()->is_fighting())
	{
		to_rob();
		this_object()->add_temp("tufei",1);
                this_player()->start_busy(1);
		call_out("go",30);}
		return;
	}
}
call_out("go",10);

}

void to_rob()
{
	int i;
	int maxskill;
	int maxexp;
	object robber;
	object me=this_player();
	maxskill=(int)me->query_skill("force");
if (!maxskill) maxskill=10;
	maxexp=me->query("combat_exp");
	message_vision(HIR"��Ȼ������һȺ�ٷˣ�\n"NOR,this_object());
	for (i=0;i<=1;i++)
	{

		robber=new(__DIR__"tufei");
		robber->move(environment(this_player()));
		robber->set_leader(this_player());
                robber->set("combat_exp",maxexp);
                robber->set_skill("kuang-jian",maxskill*1/2);
                robber->set_skill("sword",maxskill*1/2);
                robber->set_skill("parry",maxskill*1/2);        
                robber->set_skill("dodge",maxskill*1/2);        
  	        robber->set("title",HIR"���ϴ��"NOR);
if (random(10)>7 || this_player()->query("combat_exp")>1000000)
{
                robber->set_skill("kuang-jian",maxskill*2/3);
                robber->set_skill("sword",maxskill*2/3);
                robber->set_skill("parry",maxskill*2/3);        
                robber->set_skill("dodge",maxskill*2/3);        
  	        robber->set("title",HIC"������"NOR);
}
		 if(objectp(present("biaoshi", environment(this_player()))))
		{	robber->kill_ob(present("biaoshi",environment(this_player())));
			present("biaoshi",environment(this_player()))->kill_ob(robber);}
		robber->kill_ob(this_player());
		robber->set_leader(this_player());
		this_player()->kill_ob(robber);
		this_player()->start_busy(2);
	}
	
}

void owner_is_killed() { destruct(this_object()); }
