inherit NPC;
#include <ansi.h>
void create()
{
        set_name(HIW "ţͷ" NOR, ({ "niutou" }) );
        set("gender", "����" );
        set("age", 25);
	set("title", HIW "����" NOR);
        set("str", 36);
        set("cor", 24);
        set("cps", 11);
        set("per", 27);
        set("int", 27);
	set("agi", 30);
        set_temp("apply/astral_vision",1);
        set("intellgent",1);
        set("attitude", "peaceful");
        set("chat_chance", 5);
        set("chat_msg", ({
                (: random_move :),
        }) );

        set("max_force", 3000);
        set("force", 3000);

        set("long",     "ţ������ȫ�����ϵĹ��\n");

        set("combat_exp", 9999);

        set_skill("whip", 120);
	set_skill("dodge", 100);
        setup();
        carry_object(__DIR__"obj/whip")->wield();
}
int accept_object(object who, object ob)
{
		message_vision("$N��$n�ֽ�һ�������������������˰ɣ�\n",this_object(),who);
		return 1;
}
