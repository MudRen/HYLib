
inherit NPC;
void create()
{
   
   set_name("��",({ "min gong","min","gong"}) );
        set("gender", "����" );
        set("age",30);
   set("long", "����һ����̫ԭ�ɻ���񹤡�\n");
   set("combat_exp", 100000);
   set("str", 30);     
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}
