inherit NPC;

void create()
{
   set_name("���",({ "cha ke","cha","ke" }) );
        set("gender", "����" );
        set("age",30+random(10));
   set("long", "����һ����ͨ�Ĳ�͡�\n");       
   set("combat_exp", 50000);
   set("attitude", "peaceful");
   set("chat_chance",30);
   set("chat_msg",({
       "��ͺ��˿ڲ裬�����ֹ��˼��䡣\n",
   }));
   set("max_jing",100);
   set("target",1);
   setup();
 //  carry_object(__DIR__"obj/chouyi")->wear();
  
}

