 inherit NPC;
void create()
{
        set_name("��³������", ({ "tulufan trader"}) );
        set("gender", "����" );
        set("age", 42);
        set("long", "����һλ��˿��֮·���̵����ˡ�\n");
        set("combat_exp", 3000);
        set("attitude", "friendly");
        set("env/wimpy", 50);

        set("chat_chance", 30);
        set("chat_msg", ({
                "�����૵���Ϊ��׬Ǯ������Ҫ���Դ�ϵ�ڿ������Ϲ���˿��֮·��\n",
                (: random_move :),
        }) );
        set("chat_chance_combat", 15);
        set("chat_msg_combat", ({
                "����˻�е������޷Ǿ���ҪǮô��Ϊʲôһ��Ҫɱ�ң�\n",
                (: random_move :),
        }) ); 
        
        setup();
        add_money("coin", 5);
        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/nang");
        carry_object(__DIR__"obj/milk");
}       
