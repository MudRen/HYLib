#include <ansi.h>
inherit NPC;

void create()
{
	set_name("���ɶ�", ({ "linxian" }) );
	set("title", HIR "���ֵ�һ����" NOR);
	set("gender", "Ů��" );
	set("age", 22);
	set("str", 10);
	set("per", 30);
	set("long", @LONG
�������ݷ�������ü��һ˫��ϲ��ϲ����Ŀ��
�ж����������磬�о��ƽ�����ˮ��
LONG
);
	set("combat_exp", 100000);
	set("attitude", "friendly");
        set("chat_chance", 1);
        set("chat_msg", ({
"���ɶ��������������ȹ������¶������˫������֬��ϸ�㣮\n",
"���ɶ��ƺ����ȣ�������������ȣ����ѩ�׵ļ�ͦ�����ž����۵ף�\n",
"���ɶ�����Ц��Ц�������۷߶���Ƴ�˰���һ�ۣ�\n",
        }) );

	setup();
	carry_object(__DIR__"obj/sskirt")->wear();
}

int accept_fight(object me)
{
	command("say СŮ�����������Ķ��֣�");
	return 0;
}
