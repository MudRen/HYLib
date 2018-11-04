inherit NPC;
#include <ansi.h>
void create()
{
	object armor;
        set_name(RED"�պ�"NOR, ({ "master queen", "master","queen" }) );
        set("gender", "Ů��" );
        set("age", 46);
	set("agi",35);
        set("int", 30);
        set("per", 30);
        set("apprentice_available", 50);
	set("long",
		"�պ�����Ѫ�����ŵ��ߴ�����������֮�ޣ��򿴲�����Ѫ�������˶���\n"
		"���ӵ����飬����������һ�ɣ�������������������Ů�ӡ�\n"
		);
set("pubmaster",1);
if (random(2)==0)
{
	set_name(WHT"�׷ɷ�"NOR, ({ "master bai", "bai"}) );
        set("title", WHT"������Ů"NOR);
        set("long",
"�׷ɷɿ���ȥ�Ǹ�������Ů�����ǣ���\n"
               ); 

}
        set("max_neili", 25000);
        set("neili", 25000);
        set("force_factor", 30);
	set("max_qi",9999);
        set("max_jing",9999);
	set("eff_qi",9999);
	set("qi",9999);
	set("eff_jing",9999);
	set("jing",9999);

        set("attitude", "peaceful");
        set("combat_exp", 3000000);
        set("score", 90000);
        set_skill("unarmed", 100);
        set_skill("sword", 100);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("literate", 100);
		set_skill("dodge", 100);
		set_skill("ill-quan", 200);
		set_skill("fy-sword", 250);
		set_skill("jiayiforce", 220);
		set_skill("tie-steps", 250);
    	
		map_skill("unarmed", "ill-quan");
        map_skill("sword", "fy-sword");
        map_skill("force", "jiayiforce");
        map_skill("parry", "fy-sword");
        map_skill("dodge", "tie-steps");
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
(: perform_action, "sword.fengqiyunyong" :),
                (: perform_action, "unarmed.qiankun" :),
                (: perform_action, "dodge.chansi" :),
        }) );
        set("chat_chance", 5);
        set("chat_msg", ({
                (: random_move :),
        }) );
		set_temp("apply/attack", 200);set_temp("apply/defense", 200);set_temp("apply/armor", 500);set_temp("apply/damage", 600);setup();
  	         armor=new(__DIR__"obj/corclot");
		armor->set_name("����˿��",({"cloth"}) );
		armor->move(this_object());
		armor->wear();

carry_object(__DIR__"obj/longsword")->wield();
}

int accept_object(object who, object ob)
{
	int i;

	if (!(int)who->query_temp("learn_timeb"))      
		who->set_temp("learn_timeb", 0);

	if( !ob->query("money_id") )
		return 0;		


	if(who->query_skill("unarmed",1)<30)
		i=ob->value() / 50;
	else
	{
		if(who->query_skill("unarmed",1)<60)
			i=ob->value() / 100;
		else
		{
			if(who->query_skill("unarmed",1)<100)
				i=ob->value() / 100;
			else
				i=ob->value() / 100;
		}
	}
	who->add_temp("learn_timeb",i);
command("say ��Ȼ�������ѧ�ҵ��书���Ҿͳ�ȫ��ȫ��ɡ�");
	return 1;
}

int recognize_apprentice(object ob)
{
	if( ob->query_temp("learn_timeb") <= 0) return 0;
else         
ob->add_temp("learn_timeb",-1);
return 1;
}
