inherit NPC;
void create()
{
    set_name("�Ů",({"bi nu"}));
    set("gender","Ů��");
    set("combat_exp",1000);
    set("attitude","friendly");
       set("per",25);
    set("age",15);
    set("long","һ����˫Ѿ�ٵ�Ѿ��.\n");
    set_skill("unarmed",10);
    setup();
add_money("coin",30);
carry_object(__DIR__"obj/cloth")->wear();
}
