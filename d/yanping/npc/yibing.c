// bing.c �ٱ�

inherit NPC;

void create()
{
	set_name("���", ({ "yi bing", "bing" }));
	set("age", 22);
	set("gender", "����");
	set("long","�����ǹ������վ�ı�ʿ����Ȼ����ս��Ƣ���ã�Ҳ�����������Ŷ��\n");
	set("attitude", "peaceful");
	set("str", 24);
	set("dex", 16);
	set("combat_exp", 100100);
	set("shen_type", 1);

	set_skill("unarmed", 140);
	set_skill("dodge", 140);
	set_skill("parry", 140);
	set_skill("blade", 140);
	set_skill("force", 140);
	set_temp("apply/attack", 140);
	set_temp("apply/defense", 140);
	set_temp("apply/damage", 210);
	set_temp("apply/armor", 140);

	setup();
	carry_object(__DIR__"obj/gangdao")->wield();
	carry_object(__DIR__"obj/cloth")->wear();
}
