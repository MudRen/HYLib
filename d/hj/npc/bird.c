// ������
inherit NPC;
void create()
{
        set_name("������", ({ "tianlin niao", "bird" }) );
	set("race", "Ұ��");
	set("age", 1);
        set("long", "һֻ����������������ĸ����������ϵ�
���塣�����ֻ�����ϳ��裬����˯��������˵���������ϵ����ǵ�����֮
���ġ�\n");
        set("attitude", "friendly");
        set("max_qi", 100);
        set("max_jing", 100);
        set("eff_jingli", 100);	
	set("limbs", ({ "��", "���", "צ��" }) );
	set("verbs", ({ "bite", "claw" }) );
	set("combat_exp", 100);
	set_temp("apply/attack", 5);
	set_temp("apply/defense", 5);
	set_temp("apply/damage", 5);
        set("senlin", 1);
	setup();
}
