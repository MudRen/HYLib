// wang.c

#include <ansi.h>

inherit NPC;
void create()
{
	set_name("��Ԫ��", ({ "wang yuanba", "wang", "yuanba" }) );
	set("title", HIY"����"NOR"����������");
	set("nickname", HIG"���ݴ���"HIY"���޵�"NOR);
	set("gender", "����" );
	set("shen_type", 1);
	set("age", 70);
	set("str", 35);
	set("con", 25);
	set("dex", 35);
	set("int", 25);
	set("long",
"��Ԫ��������ʮ���꣬�����⣬���һ�Գ����İ���Ʈ����ǰ������
���壬����Ǻ�ॵ�������ö�쵰��С�Ľ𵨡���������������������
��Ѱ���������������򴿸���������Ԫ���������յ�ȴ����ö�Ƴγε�
�𵨣���֮����������һ�����࣬���Ҵ��Ի���֮����\n" );
	set("combat_exp", 700000);
	set("attitude", "friendly");
	set_skill("blade", 300);
	set_skill("dodge", 300);
	set_skill("unarmed", 300);
	set_skill("throwing", 300);
	set_skill("feixing-shu", 300);
	set_skill("yanfly", 300);
	set_skill("parry", 300);
	map_skill("throwing", "feixing-shu");
	map_skill("parry", "feixing-shu");
	map_skill("dodge", "yanfly");

	setup();
	carry_object(__DIR__"obj/jindan")->wield();
	carry_object("/clone/misc/cloth")->wear();
	add_money("gold", 1);
}

