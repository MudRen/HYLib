inherit NPC;
#include <ansi.h>
void create()
{
	set_name(HIG"ʯ����"NOR, ({ "master guanyin", "master","guanyin" }) );
	set("gender", "Ů��" );
	set("age", 25);
	set("int", 30);
	set("str",60);
	set("per", 39);
	set("agi",100);
        set("apprentice_available", 50);

	set("long",
"ʯ�����������������ǽ��˲�������ģ���Ϊ����������ȫ��ռ����
���ǵ����������кܶ��˶����á�������������Ů�ӵ����������ǹ�����
������˫�۾������������ᡣ�кܶ��˶����á���ɽ����������Ů��ü��
�������������ʵĴ�ɽҲ��������ü����Լ��
"
		);
        set("force_factor", 400);
        set("chat_chance", 5);
        set("chat_msg", ({
                "ʯ������������......�㲻�����ϣ���\n",
                "ʯ����Ц��Ц���ֵ��������֪��������ʲô�ط�����\n",
		"ʯ�����۹�ͻȻ���ʣ��������������֪����Ϊ�λ�����������\n",
                (: random_move :),
        }) );
set("pubmaster",1);

if (random(2)==0)
{
	set_name(HIC"����"NOR, ({ "master die", "die"}) );
        set("title", HIC"ŭ����"NOR);
        set("long",
"������������֮һ����\n"
               ); 
        set("chat_chance", 5);
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
	set("agi",25);
        set("int",30);
        set("combat_exp", 99999999);
        set_skill("unarmed", 100);
        set_skill("blade", 150);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("literate", 100);
	set_skill("dodge", 100);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.taixubaihuan" :),
                (: perform_action, "unarmed.yaozhan" :),
        }) );
	set_skill("kongshoudao", 200);
	set_skill("bat-blade", 230);
	set_skill("ghosty-force", 300);
	set_skill("ghosty-steps", 200);

	map_skill("unarmed", "kongshoudao");
        map_skill("blade", "bat-blade");
        map_skill("force", "ghosty-force");
        map_skill("parry", "bat-blade");
        map_skill("dodge", "ghosty-steps");
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 600);
	set_temp("apply/attack", 200);set_temp("apply/defense", 200);set_temp("apply/armor", 500);set_temp("apply/damage", 600);setup();
	carry_object(__DIR__"obj/whitecloth")->wear();
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
