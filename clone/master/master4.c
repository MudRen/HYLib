//XXDER
inherit NPC;
#include <ansi.h>
void create()
{
        set_name("��ˮ����", ({ "master shenshui", "master", "shenshui" }) );
        set("title", HIW"ˮĸ����"NOR);
        set("gender", "Ů��");
        set("age", 33);
        set("long",
"һλ���ϴ�����ɳ����Ů�����ڵ����ϣ�����Ȼ�������������ݣ�ȴ���Ըо�����
�Ǿ��ѵ����ʺ;���Ͷ���ĳ�����ϡ�\n"
                );
        set("attitude", "peaceful");
        set("class", "shenshui");
        set("apprentice_available", 2);

        set("int", 28);
        set("spi", 26);
set("pubmaster",1);

if (random(2)==0)
{
	set_name(GRN"������"NOR, ({ "master ding", "ding"}) );
        set("title", GRN"������"NOR);
        set("long",
"������������֮һ����\n"
               ); 
        set("chat_chance", 3);
        set("chat_msg", ({
                (: random_move :),
        }) );

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
        set("per", 38);
        set("cps", 30);
        set("chat_chance_combat", 80);
        set("neili", 1200);
        set("max_neili", 1200);
        set("force_factor", 18);

        set("combat_exp", 15000000);
        set("score", 90000);

        set_skill("unarmed", 100);
        set_skill("sword", 100);
        set_skill("throwing", 100);
        set_skill("force", 90);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("literate", 100);
  //      set_skill("perception", 100);

        set_skill("nine-moon-steps", 250);
        set_skill("nine-moon-claw", 250);
        set_skill("nine-moon-force", 200);
        set_skill("nine-moon-sword", 200);

        map_skill("dodge", "nine-moon-steps");
        map_skill("unarmed", "nine-moon-claw");
        map_skill("force", "nine-moon-force");
        map_skill("sword", "nine-moon-sword");

        set_temp("apply/defense", 100);
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 600);
       set("chat_chance_combat", 1);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.suicidal" :),
        }) );
         set("chat_chance", 5);
        set("chat_msg", ({
                (: random_move :),
        }) );
       set_temp("apply/attack", 200);set_temp("apply/defense", 200);set_temp("apply/armor", 500);set_temp("apply/damage", 600);setup();
        carry_object(__DIR__"obj/ghostyboots")->wear();
        carry_object(__DIR__"obj/ghostycloth")->wear();
        carry_object(__DIR__"obj/ghostygirth")->wear();
        carry_object(__DIR__"obj/ghostyribbon")->wear();



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
