
inherit NPC;

void create()
{
   set_name("��ũ",({ "guo nong","nong"}) );
        set("gender", "����" );
        set("age",38);
   set("long", "����һλ��ͨ�Ĺ�ũ��\n");       
   set("combat_exp", 50000);
   set("str", 10);
   set("attitude", "peaceful");   
   setup();
   add_money("coin",50);
}

