// Modify By River 98/12
inherit NPC;

void create()
{
       set_name("���ϴ��", ({"lingnan dadao", "dadao", "dao"}));
       set("long", "����һ����Ŀ���Ĵ��������͸��һ�������ɱ����\n");
       set("gender", "����");
       set("attitude", "heroism");
       set("age", 40+random(20));
       set("shen_type", -1);
       set("shen", -20000);
       set("unique", 1);
       set("str", 32);
       set("int", 24);
       set("con", 30);
       set("dex", 30);
       set("max_qi", 2700);
       set("max_jing", 2000);
       set("neili", 3500);
       set("max_neili", 3500);
       set("jiaji", 150+random(50));
       set("combat_exp", 600000);

       set_skill("force", 170);
       set_skill("dodge", 160);
       set_skill("unarmed", 160);
       set_skill("parry", 165);

       setup();
       add_money("silver", random(90));
       carry_object("/clone/misc/cloth")->wear();
}
