 // tea_waiter.c
inherit NPC;
void create()
{
        set_name("�ο�", ({ "you ke" }) );
        set("gender", (random(2)? "Ů��":"����") );
        set("age", random(40)+10);
        set("long",
                "һ��Ľ��ǰ��������ο����ǧ�𶴵��ˡ�\n");
        set("combat_exp", 5+random(500));
        set("chat_chance", 5);
        set("chat_msg", ({
                "�ο�ָ����Χ�ľ�ɫ̾��������ѽ����\n",
                "�ο͵�������Ϊ����ķ���صأ���\n",
                "�οͶ���˵�����Һ������Ķ������㣿\n",
                "�ο�ָ��������⣬�ⲻ�ǵ������ֵ�һ�����𣿣�\n",
                "�ο����Ķ���˵������˵�������ԭ���˸������\n",
                "�οͶ���˵������Ҳ��Ҫȥ���������������ǽ����У�\n",
        }) ); 
        set("attitude", "friendly");
        setup();
        carry_object("/clone/misc/cloth")->wear(); 
}  
