inherit NPC;
 
void do_drink();
 
void create()
{
        seteuid(getuid());
        set_name("�����", ({"guard", "boat guard", "boater"}));
        set("long",
                "һ����ѬѬ�Ĵ����\n");
        set("gender","����");
        set("combat_exp", 999999);
        set_skill("unarmed", 100);

        setup();
        carry_object("clone/cloth/cloth")->wear();
}
int accept_object(object me, object obj)
{
        command("smile");
        command("say ��л��λ" + RANK_D->query_respect(me) +
"����һ�����������Ŀ��ĵģ�");
        return 1;
}

