inherit NPC;
#include <ansi.h>
string *first_name = ({ "��Ƥ", "����", "�Ľ�", "����"});
string *name_words = ({ "��"});
void create()
{
        string name;
        name = first_name[random(sizeof(first_name))];
        name += name_words[random(sizeof(name_words))];
        set_name(name,({"du she"}));
	set("race", "Ұ��");
        set("long", "һ��һ�߶೤����ͷ���Ե�С�ߡ�\n");
	set("age", 15);
	set("max_jing", 600);
	set("max_qi", 600);
	set("eff_jing", 600);
	set("eff_qi", 600);
	set("jing", 600);
	set("qi", 600);

	set("limbs", ({ "ͷ��", "����", "β��" }) );
	set("verbs", ({ "bite" }) );
	set("attitude", "peaceful");
set("no_get",1);
set("no_drop",1);
	set_skill("sword",40);
	set_skill("club",40);
	set_skill("whip",40);
	set_skill("throwing",40);
	set_skill("parry",40);
	set_skill("dodge",40);

	set("str", 30);
	set("con", 50);

	set_temp("apply/attack", 60);
	set_temp("apply/defense", 60);
	set_temp("apply/armor", 60);
	set_temp("apply/damage", 100);

	set("combat_exp", 28000);
 

	setup();
}


void init()
{	
	add_action("do_finish", "finish");
	add_action("do_go", "go");
	add_action("do_guard", "halt");
    if(this_player()->query("id")==this_object()->query_temp("host"))
	this_player()->start_busy(1);

}

void unconcious()
{            
	::die();       
}	

int do_finish()
{	object ob,player;
    int exp,pot,base_exp,add_exp,count,i;
    ob=this_object();
	player=this_player();
	if (ob->is_fighting())
	return 0;
	if(player->query_temp("bt2_song")
	&&ob->query_temp("host")==player->query("id")
	&&environment(ob)->query("short")=="�����߳�")
	{
 exp=90+random(90);
 pot=50+random(60);
if (player->query("combat_exp") <800000)
{
 exp=50+random(50);
 pot=40+random(40);
}
       player->add("potential",pot);
       player->add("combat_exp",exp);
       player->delete_temp("bt2_song");
player->add("shen",-50);
	   tell_object(player,HIG"������͵����߳����������!\n"+
                       NOR);

	   tell_object(player,HIW"�㱻�����ˣ�\n" + 
                       chinese_number(exp) + "��ʵս����\n" +
                       chinese_number(pot) + "��Ǳ��\n"+
                       NOR);
	   destruct(ob);
		return 1;
	 }	
else 	   tell_object(player,HIG"������ʲô!\n"+NOR);
return 1;
}

int do_guard(string arg)
{
        write(this_player()->query("name")+"�������ڲ�����halt��\n");
        return 1;
}

int do_go(string arg)
{
object ob;
object me=this_object();
if (!me) return 0;

	if(this_player()->query_temp("bt2_song"))
{
if (me->is_fighting() && this_player()->query_temp("bt2_song")
&& this_player()->query("id")==me->query_temp("host"))
{
write(this_object()->query("name")+"���ں�ҧ���أ�������õ����߻��ᣡ\n");
return 1;
}

//if (random(2)>1)
if(random(8)==1
&& !environment(me)->query("no_fight"))
{
ob=new(__DIR__"man"); 
if (environment(me))
ob->move(environment(me));
me->start_busy(1);
this_player()->start_busy(1);
write(this_object()->query("name")+"ͻȻ�򸽽�����ҧ����ȥ��\n");
me->kill_ob(ob);
ob->kill_obj(me);
return 1;
}
if (me->is_fighting()&& this_player()->query_temp("bt2_song")
&& this_player()->query("id")==me->query_temp("host"))
{
write(this_object()->query("name")+"���ں�ҧ���أ�������õ����߻��ᣡ\n");
return 1;
}
}
}
int hit_ob(object me, object ob, int damage)
{
    if ((int)ob->query("combat_exp") > 10000) return 1 ;
	if( random(damage) > (int)ob->query_temp("apply/armor")
	&&	(int)ob->query_condition("snake_poison") < 10 ) {
		ob->apply_condition("snake_poison", 20);
        tell_object(ob, HIG "����ñ�ҧ�еĵط�һ����ľ��\n" NOR );
	}
}
