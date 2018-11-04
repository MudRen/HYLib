// snake.c

inherit NPC;
void use_poison();

void create()
{
        set_name("��Ҷ��", ({ "big snake" }) );
	set("race", "Ұ��");
        set("age", 4);
        set("long", "һ���綾��ȫ�������ӵ���\n");

        set("attitude", "aggressive");
        set_skill("dodge", 200);
	set("limbs", ({ "ͷ��", "����", "β��" }) );
	set("verbs", ({ "bite" }) );        
        set("combat_exp", random(2999999));
	set("bellicosity", 300 );
        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                (: use_poison :),
        }) );
	set_temp("apply/attack", 10);
	set_temp("apply/damage", 10);
	set_temp("apply/armor", 10);
        setup();
}
void use_poison()
{
        object *enemy, ob;
        string msg;

        enemy = query_enemy();
        if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];

        tell_object(ob, "��������Ͼ�ʹ������һ��������������ӡ�ۡ�\n");
	ob->receive_wound("qi",40);
	ob->apply_condition("snake_poison", (int)this_player()->query_condition("snake_poison") + random(3)+3);
}
void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) ) {
                kill_ob(ob);
        }
}

