 // COPYRIGHT (C) Apstone, Inc. 1998
inherit NPC;
void create()
{
        set_name("˫���缦צ���ϸ�", ({ "old woman", "ugly old woman" }) );
        set("long",
"��������ɴ�ۣ�������������ס�ˣ�ֻ¶��һ˫�缦צ���֡�
ȫ���ڲ�ͣ�س鴤�ţ�����\n");
        set("attitude", "heroism");
        set("gender", "Ů��");
        set("per", 3);
        set("age",69);
        set("chat_chance", 1);
        set("chat_msg", ({
"�ϸ������������Ϊʲô��������˭����Ū�����ڵĵز�����ask old woman about whom��\n",
        }) );
        set("inquiry", ([
                "whom" : "�����������Ǹ������������ˣ���\n",
        ]) );
        set("combat_exp", 1000000);
        set_skill("unarmed", 150);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("move", 150);
        set_skill("nine-moon-claw",100);
        set_skill("chaos-steps",100);
        map_skill("unarmed","nine-moon-claw");
        map_skill("dodge","chaos-steps");
        map_skill("move","chaos-steps");
        setup();
        carry_object(__DIR__"obj/blackcloth")->wear();
}    
