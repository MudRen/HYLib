inherit NPC;
void create()
{
    set_name("������", ({ "ju mang", "mang" }) );
	set("race", "Ұ��");
	set("age", 70);
    set("long", "һ��������������������\n");
    set("attitude", "aggressive");
	set("limbs", ({ "ͷ��", "����", "β��", "����" }) );
	set("verbs", ({ "sweep", "twist", "bite" }) );
        set("str", 190);
        set("con", 190);
	set("qi",30000);
	set("max_qi",30000);
	set("jing",30000);
	set("max_jing",30000);
	set("combat_exp", 550000);
	set_temp("apply/attack", 200);
	set_temp("apply/defense", 200);
	set_temp("apply/damage", 400);
	set_temp("apply/armor", 800);
	setup();
}

void die()
{
	object ob;
    message_vision("$N���������˼��¾Ͳ����ˡ�\n", this_object());
if (random(10) > 6)
{
	ob = new("/d/baituo/obj/shenshezhang");
	ob->move(environment(this_object()));
}
	destruct(this_object());
}
	
int hit_ob(object me, object victim, int damage)
{
        victim->apply_condition("snake_poison",
                victim->query_condition("snake_poison") + 8);
        return 0;
}