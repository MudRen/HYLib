
inherit NPC;

void create()
{
   set_name("С��",({ "xiao jie","xiao","jie"}) );
        set("gender", "Ů��" );
        set("age",18);
   set("long", "�����ϲ��ǵ�һλС�㡣\n");       
   set("combat_exp", 50000);
   set("str", 10);
   set("per", 22);
   set("attitude", "peaceful");
   
   setup();
   add_money("coin",50);
}

