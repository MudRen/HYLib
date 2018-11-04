// servant.c

inherit NPC;
#include <ansi.h>
void create()
{
        set_name("���Ŵ�ѩ", ({ "master ximen", "ximen", "master" }) );
        set("title", WHT"��÷ׯ��"NOR);
        set("gender", "����");
        set("age", 34);
        set("long",
"���Ŵ�ѩ���ǵ�����������֮һ�������Ѿ������ˣ��޽����ľ��磮��\n"
               ); 

        set("attitude", "peaceful");
        set("combat_exp", 80000000);
        set("agi",25);
        set("int",40);
        set("long",
"���Ŵ�ѩ���ǵ�����������֮һ�������Ѿ������ˣ��޽����ľ��磮��\n"
               ); 

                set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.hunranyijian" :),
                (: perform_action, "dodge.feitiantui" :),

		"���Ŵ�ѩ��Ц������˷������ɱ�ң�\n"
        }) );
        set("chat_chance", 1);
        set("chat_msg", ({
                "���Ŵ�ѩŭ�����½С�������ӵ�����ɽׯ����ҲҪɱ���㣡��\n",
                (: random_move :),
        }) );
if (random(2)==0)
{
	set_name(GRN"����"NOR, ({ "master lang", "lang"}) );
        set("title", GRN"��������"NOR);
        set("long",
"�������ǵ�����������֮һ�������Ѿ������ˣ��޽����ľ��磮��\n"
               ); 

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.hunranyijian" :),
                (: perform_action, "dodge.feitiantui" :),
		"������Ц������˷������ɱ�ң�\n"
        }) );
        set("chat_chance", 5);
        set("chat_msg", ({
                (: random_move :),
        }) );

}

        set("str", 30);
        set("int", 30);
        set("cor", 300);
        set("cps", 30);
        set("con", 30);
        set("per", 30);

set("pubmaster",1);
        set("max_neili", 25000);
        set("neili", 25000);
        set("force_factor", 30);
	set("max_qi",9999);
        set("max_jing",9999);
	set("eff_qi",9999);
	set("qi",9999);
	set("eff_jing",9999);
	set("jing",9999);




        set_skill("force", 100);
        set_skill("unarmed", 100);
        set_skill("sword", 150);
        set_skill("parry", 100);
        set_skill("dodge", 80);
        set_skill("throwing", 50);
	
        set_skill("doomforce", 200);
        set_skill("doomstrike", 200);
        set_skill("doomsteps", 290);
	set_skill("doomsword",220);

        map_skill("force", "doomforce");
        map_skill("unarmed", "doomstrike");
        map_skill("sword", "doomsword");
        map_skill("dodge", "doomsteps");


       
        set_temp("apply/attack", 200);set_temp("apply/defense", 200);set_temp("apply/armor", 500);set_temp("apply/damage", 600);setup();

        carry_object(__DIR__"obj/xuejian")->wield();
	carry_object(__DIR__"obj/xuecloth")->wear();
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
