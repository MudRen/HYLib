//Cracked by Kafei
// shinu.c ����ɽׯ�̼�
#include <ansi.h>

inherit NPC;

void create()
{
        set_name("�̼�", ({ "shi ji","ji"}));
        set("long", "����ɽ������һ����檣���̬��ȣ�Ц��ұ�ޡ�\n");
        set("gender", "Ů��");
        set("age", 20);

        set_skill("hand", 40);
        set_skill("dodge", 40);
        set_skill("parry", 40);
        set_skill("force", 40);

        set("str", 19);
        set("int", 20);
        set("con", 18);
        set("dex", 20);

        set("max_neili", 500);
        set("combat_exp", 30000);

        set("attitude", "peaceful");

	setup();
	carry_object(__DIR__"wcloth")->wear();
}
