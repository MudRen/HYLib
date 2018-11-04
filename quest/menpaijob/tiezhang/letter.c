#include <ansi.h>
inherit ITEM;
int consider_lv(object ob,int a);
void to_rob();
void create()
{
        set_name(HIR"Ȱ����"NOR, ({"xin", "letter"}));
        set("long",
               "�������ư��и������ҪȰ���顣\n");
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
object obn;
int i;
int b;
string targ;
int exp,pot;
        if (!arg||!ob=present(arg,environment(me)))
                return notify_fail("��Ҫ��Ȱ�����͸�˭��\n");
        targ=ob->query("name");
if ( targ != me->query("quest/quest") ) return notify_fail("�����͸�"+me->query("quest/quest")+"��Ȱ���飬����ô������Ҹ��أ�\n");
    if(me->is_busy())
        return notify_fail("��������æ��\n");
     if (me->is_fighting()) 
        return notify_fail("���������������!\n");

        if (userp(ob)) return notify_fail("��Ū�����˰ɣ�\n"); //��ҿ�������ͬ��NPC������
        if ( (int) me->query("task_time") < time() )
        {
             return notify_fail(targ+"�����˵������������,���Ѿ��յ�����������Ȱ�����ˣ���\n");
        }
        tell_object(me,"���Ȱ���齻����"+targ+"��\n" NOR );
        if (me->query("tzjob") == 2)        
{
        i=me->query_skill("force");
        obn = new(__DIR__"xiashi");
        obn->set("combat_exp",me->query("combat_exp"));
        obn->set("max_qi",me->query("max_qi"));
        obn->set("eff_qi",me->query("max_qi"));
        obn->set("qi",me->query("max_qi"));
        obn->set("max_jing",me->query("max_qi"));
        obn->set("eff_jing",me->query("max_qi"));
        obn->set("jing",me->query("max_qi"));

        obn->set("max_jingli",me->query("max_jingli"));
        obn->set("eff_jingli",me->query("max_jingli"));
        obn->set("jingli",me->query("max_jingli"));
        obn->set("max_neili",me->query("max_neili"));
        obn->set("neili",me->query("max_neili"));
        obn->set_skill("force", i*3/4);
        obn->set_skill("huifeng-jian", i*3/4);
        obn->set_skill("kunlun-shenfa", i*3/4);
        obn->set_skill("strike", i*3/4);
        obn->set_skill("kunlun-zhang",i*3/4);
        obn->set_skill("jinding-zhang",i*3/4);
        obn->set_skill("dodge", i*3/4); 
        obn->set_skill("sword", i*3/4); 
        obn->set_skill("linji-zhuang", i*3/4); 
        obn->set_skill("parry", i*3/4); 
        obn->set_skill("literate", i*3/4);
        obn->set("shen",(me->query("combat_exp")/20));
if (me->query("combat_exp") > 8000000)
{
        obn->set_temp("apply/attack", 200);
        obn->set_temp("apply/defense",200);
        obn->set("chat_chance_combat", 80);
obn->set("chat_chance_combat", 40);
}
        obn->move(environment(me));
        message_vision("\n" + HIW + "ͻȻһ����Ӱ��$N���˹�����\n"NOR, me);
        message_vision("\n" + HIR + "$n��$N���һ��������������ư���߹���������������\n"NOR, me, obn);
        me->kill_ob(obn);
        me->set("tzjob",1);
        obn->kill_ob(me);
        obn->set_leader(me);
}
        exp=me->query("quest/exp_bonus")+50;
        pot=me->query("quest/pot_bonus")+30;
//b=this_object()->query_temp("tufei");
//if (b>0)
//{
//        /exp=me->query("quest/exp_bonus")+50+b*60;
//        pot=me->query("quest/pot_bonus")+30+b*60;
//}
if (exp > 500) exp=500;
if (pot > 400) pot=400;

        if (me->query("tzjob") == 0)               
{
        tell_object(me,HIW""+targ+"����һ���,һ��׵���֪����....���㱻�����ˣ�\n"
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
	message_vision(HIR"�Ҳ�Ҫ�ⶫ����\n"NOR,me);
}
void go()
{	
if (this_player())
{
		this_player()->start_busy(1);
  if (random(100)<3&& !environment(this_player())->query("no_fight") 
    && !this_player()->is_fighting())
	{	
        if (this_object()->query_temp("tufei")<2 && !environment(this_player())->query("no_fight"))
	{
		to_rob();
		this_object()->add_temp("tufei",1);
                this_player()->start_busy(3);
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
	maxskill=me->query_skill("force");
if (!maxskill) maxskill=10;
	maxexp=me->query("combat_exp");
	message_vision(HIR"��Ȼ������һȺ�ٷˣ�\n"NOR,this_object());
	for (i=0;i<=1;i++)
	{

		robber=new(__DIR__"tufei");
		robber->move(environment(this_player()));
		robber->set_leader(this_player());
                robber->set("combat_exp",maxexp*3/4);
                robber->set_skill("kuang-jian",maxskill*1/2);
                robber->set_skill("sword",maxskill*1/2);
                robber->set_skill("parry",maxskill*1/2);        
                robber->set_skill("dodge",maxskill*1/2);        
  	        robber->set("title",HIR"���ϴ��"NOR);
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

