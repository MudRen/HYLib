
inherit NPC;

void create()
{
   set_name("�ٱ�",({ "bing" }) );
        set("gender", "����" );
        set("age", 32);
   set("long", "����������µĵ���Ĺٱ���\n");
       
   set("combat_exp",200000);
   set("str", 26);
   set("per", 22);
   set_skill("unarmed",120);
   set_skill("dodge",120);
   set_skill("sword",120);
   set_skill("parry",120);
    setup();
   carry_object(__DIR__"obj/junfu")->wear();
   carry_object(__DIR__"obj/gangjian")->wield();
  
}

void die()
{
	object me,killer;
    me=this_object();
	killer=me->query_temp("last_damage_from");
	if(killer->query_temp("defence_girl"))
	{killer->set_temp("defence_ok",1);
	killer->set_temp("busy_time",time());}
	return ::die();
}