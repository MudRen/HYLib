 inherit NPC;
void create()
{
        set_name("�ɹ���", ({ "mongol"}) );
        set("gender", "����" );
        set("age", 35);
        set("str", 10);
        set("long", @LONG
һ����׳���͵����ˡ�
LONG
);
        set("attitude", "peaceful");
        set("title", "�����");
        set("combat_exp", 600);
        set_skill("unarmed", 50);
        set_skill("bloodystrike", random(20)+10);
        set_skill("force", 40);
        map_skill("unarmed", "bloodystrike");
        set_skill("iron-cloth", random(40)+10);
        set("chat_chance", 1);
        set("chat_msg", ({
                (: random_move :),
                "\n����ͻȻ�������������ഫ���ڴ�ر�Ե��һ�����컹�ߵ�ɽ�壬ɽ\n�ϲ�������Ų����ı�ѩ�������ֱȶ������µ���ħ��\n",
        }) ); 
        setup();
        carry_object(__DIR__"obj/magcloth")->wear();
 
}       
