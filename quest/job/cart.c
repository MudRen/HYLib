
#include <ansi.h>
inherit ITEM;
void to_rob();
void create()
{
        set_name("�ڻ�", ({ "prize"}) );
        set_weight(3000);
        set("no_get", 1);
       set("unit", "��");
	set("long", "һ�����������滭�ų����ھֵ����졣\n");
	set("value", 0);
	set("no_put",1);
	set("no_get",1);
	set("no_drop",1);
	set("no_steal",1);
    
}
void init()
{
	add_action("do_finish","finish");
	add_action("do_guard", "guard");
	add_action("do_go", "go");
	remove_call_out("go");
	call_out("go",0);	
}
int do_finish()
{
	object me,ob,where;
	int exp,pot;
	me=this_player();
	ob=this_object();
       where = environment(me);
if (!environment(me)) return notify_fail("��������æ��\n");
if (!me)return notify_fail("��������æ��\n");
    if(me->is_busy())
        return notify_fail("��������æ��\n");
     if (me->is_fighting()) 
        return notify_fail("���������������!\n");
	if(file_name(where) == me->query_temp("end_place"))
	 {
  if (random(100)<8&& !environment(this_player())->query("no_fight") )
	{	
        if (this_object()->query_temp("tufei")<1 && !environment(this_player())->query("no_fight"))
	{
		to_rob();
		this_object()->add_temp("tufei",1);
                this_player()->start_busy(1);
	}
		return 1;
	}
	   if(objectp(present("biaoshi", environment(me))))
		{ remove_call_out("aaa");
		call_out("aaa",3,ob);
		exp=random(300)+100;
		destruct(present("biaoshi",environment(me)));
		destruct(present("biaoshi",environment(me)));
		  pot=exp/5;
		  me->add("combat_exp",exp);
		  me->add("potential",pot);
		  me->add("shen",100);
	message_vision(HIC"ͻȻ�Ӱ����߳�һ�˳�$N������$N�ʵ�������ǧ��.\n���˴� �����������ˡ�\n$N���Է������˰��ţ�������е��ڻ������˶Է���\n"NOR,me);	
	tell_object(me,"�㱻������\n"+chinese_number(exp)+"��ʵս����\n"
				+chinese_number(pot)+"��Ǳ��\n");
	me->delete_temp("on_biao");
	me->delete_temp("end_place");
	me->delete_temp("biao_place");
		} else {remove_call_out("aaa");
		call_out("aaa",3,ob);
		exp=random(300)+100;
		  pot=exp/7;
		  me->add("combat_exp",exp);
		  me->add("potential",pot);
		  me->add("shen",100);
	message_vision(HIC"ͻȻ�Ӱ����߳�һ�˳�$N������$N�ʵ�������ǧ��.\n���˴� �����������ˡ�\n$N���Է������˰��ţ�������е��ڻ������˶Է���\n"NOR,me);	
	tell_object(me,"�㱻������\n"+chinese_number(exp)+"��ʵս����\n"
				+chinese_number(pot)+"��Ǳ��\n");
	me->delete_temp("on_biao");
	me->delete_temp("end_place");
	me->delete_temp("biao_place");

	}}
	return 1;
}
void go()
{	
if (!this_player()) return;
		this_player()->start_busy(1);
		if (random(100)<10&& !environment(this_player())->query("no_fight") )
	{
		if (this_object()->query_temp("tufei")<3&& !environment(this_player())->query("no_fight"))
	{
	        to_rob();
		this_object()->add_temp("tufei",1);
                this_player()->start_busy(1);
		call_out("go",30);}
		return;
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
	maxexp=me->query("combat_exp");
	
	message_vision(HIR"��Ȼ������һȺ�ٷˣ�\n"NOR,this_object());
	for (i=0;i<=random(2)+1;i++)
	{
		robber=new(__DIR__"tufei");
		robber->move(environment(this_player()));
		robber->set_leader(this_player());
       robber->set("str", me->query("str"));
        robber->set("dex", me->query("dex")*2);
        robber->set("per", me->query("per"));
        robber->set("qi", me->query("qi")* 3/4);
        robber->set("eff_qi", me->query("eff_qi")* 3/4);
        robber->set("jing", me->query("jing")* 3/4);
        robber->set("neili", me->query("neili")* 3/4);
        robber->set("max_neili", me->query("max_neili")* 3/4);
        robber->set("eff_jing", me->query("eff_jing")* 3/4);
        if (maxskill >10)
{
        robber->set_skill("kuang-jian",me->query_skill("force")/2);
        robber->set_skill("sword",me->query_skill("force")/2);
        robber->set_skill("parry",me->query_skill("force")/2);        
}
        robber->set("combat_exp",me->query("combat_exp")* 3/4);
//                robber->set("combat_exp",maxexp);
//                robber->set_skill("kuang-jian",maxskill*2/3);
//                robber->set_skill("sword",maxskill*2/3);
//                robber->set_skill("parry",maxskill*2/3);        
//                robber->set_skill("dodge",maxskill*2/3);        
  	        robber->set("title",HIG"���ϴ��"NOR);
		 if(objectp(present("biaoshi", environment(this_player()))))
		{	robber->kill_ob(present("biaoshi",environment(this_player())));
			present("biaoshi",environment(this_player()))->kill_ob(robber);}
                robber->set_leader(this_player());
		robber->kill_ob(this_player());
		robber->set_leader(this_player());
		this_player()->kill_ob(robber);
		this_player()->start_busy(2);

	}
	
}
int do_guard(string arg)
{
        write(this_player()->query("name")+"�������ڲ�����guard��\n");
        return 1;
}
void aaa(object ob)
{
 destruct(ob);
}

int do_go(string arg)
{
	if(this_player()->query_temp("hu_song")==1)
{
	if(objectp(present("tufei", environment(this_object()))))
	{
        write(this_object()->query("name")+"���ĸ����������ˣ��㲻���ߣ�\n");
        return 1;
//	obj->kill_ob(present("gong zi",environment(this_player())));
// 	present("gong zi",environment(this_player()))->kill_ob(obj);
// 	present("gong zi",environment(this_player()))->start_busy(6);
//        obj->set_leader(present("gong zi",me));
//        obj->kill_ob(present("gong zi",me));
 	}
}
}
