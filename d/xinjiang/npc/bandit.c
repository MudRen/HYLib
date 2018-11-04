 // bandit.c
inherit NPC; 
void create()
{
        set_name("����", ({ "bandit" }) );
        set("gender", "����");
        set("age", 33);
        set("long",
                "��һ��������⣬һ�������ɷ��ģ��������������η��\n");
        set("combat_exp", 600);
        set("score", 60);
        set("attitude", "friendly");
        set_skill("sword", 10);
        set_skill("parry", 10);
        set_skill("dodge", 10);
        setup();
        carry_object("/clone/misc/cloth")->wear(); 
        carry_object(__DIR__"obj/short_sword")->wield();
        add_money("coin", 3);
}
void init()
{
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) 
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
} 
void greeting(object ob)
{   
        if( !ob || environment(ob) != environment() )
                return;
        if (ob->query("class") != "bandit")
        {
                message_vision("$N��������������������ֵ��ǣ�������ڣ���\n", this_object() );
                this_object()->kill_ob(ob);
                ob->kill_ob(this_object());
        }
        else if(ob->query("class")=="bandit")
        {
                message_vision("$N������Ц�����ֵܽ����ֵ������ҽ��᣿\n", this_object() );
        }
        return;
}     