
inherit NPC;

void create()
{
   set_name("����",({ "gong zi","gong","zi"}) );
        set("gender", "����" );
        set("age", 32);
   set("long", "����һ��ס���ϲ��Ĺ��Ӹ磬�����������£��������䡣\n");
       
   set("combat_exp", 50000);
   set("str", 10);
   set("per", 22);
   set("attitude", "peaceful");
   
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

