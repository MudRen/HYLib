
inherit NPC;

void create()
{
   //reload("yy_yaodian_wang");
   set_name("��ҩʦ",({ "wang yaoshi","wang","yaoshi"}) );
        set("gender", "����" );
        set("age", 40);
   set("long", "���ǰ������ҩʦ���������кܶ������ҩ�\n");
    set("shop_id",({ "wang yaoshi","wang","yaoshi"}) );
   set("combat_exp",300000);
   set("str",26);
   set("per", 22);
   set("force",500);
   set("max_force",500);
   set("qi",800);
   set("max_qi",800);
   set("sen",500);
   set("max_sen",500);
   set_skill("dodge",80);
   set_skill("parry",80);
   set_skill("unarmed",80);
   set("attitude", "peaceful");
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}


int regenerate()
{
        set("called", 0);
        return 1;
}
