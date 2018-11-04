#include <ansi.h>

inherit NPC;
int about_he();
string summon_more(object me);

void create()
{
	set_name("����", ({ "qiu yi","qiu" }));
	set("long",
	    "����һ����ʮ�������������, Ũü����,\n"+
	    "��һ���������µĳ���, ��ʹ�����Լ��־���.\n"+
	    "����ɫ��Ȼ.\n");
	set("title", HIR"�ϱ�˫ӥ"NOR);
	set("gender", "����");
	set("age", 46);
	set("nickname", HIC "��ӥ" NOR);
	set("shen_type",1);
	set("attitude", "peaceful");

        set("str", 60);
        set("int", 30);
        set("dex", 50);
        set("cps", 30);
        set("spi", 30);
	set("kee", 5000);
	set("max_kee", 5000);
	set("sen", 5000);
	set("max_sen", 5000);

        set("force", 5000);
        set("max_force", 5000);
        set("force_factor", 50);

        set("atman", 2000);
        set("max_atman", 2000);

        set("mana", 4000);
        set("max_mana", 2000);
        set("mana_factor", 50);



        set("combat_exp", 3000000);
        set("score", 20000);

        set_skill("literate", 200);
        set_skill("force", 200);
        set_skill("unarmed", 200);
        set_skill("dagger", 200);
        set_skill("parry", 200);
        set_skill("dodge", 300);
  
        set("chat_chance", 10);
        set("chat_msg", ({
                (: random_move :),
        }) );

	setup();
        carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}
