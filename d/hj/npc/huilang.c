inherit NPC;
void create()
{
    set_name("�����", ({ "huilang", "lang" }) );
    set("race", "Ұ��");
    set("age", 10);
    set("long", "һͷ�ߴ�Ķ���, �������, ¶����ɭɭ�������\n");
    set("attitude", "aggressive");
	set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
	set("verbs", ({ "bite", "claw" }) );
        set("max_qi", 300);
        set("max_jing", 200);
        set("eff_jingli", 200);
	set("combat_exp", 3000);
	set("chat_chance", 5);
	set("chat_msg", ({
                "����~~~~������Ƿ���һ���ƽС�\n",
                "����Ƿ���һ���ƽУ�������ʱ��Ҫ��������\n",
	}) );
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 8);
	set_temp("apply/damage", 10);
	set_temp("apply/armor", 4);
        set("senlin", 1);
	setup();
}
