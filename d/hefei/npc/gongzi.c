
inherit NPC;

void create()
{
   set_name("���Ӹ�",({ "gongzi ge","gongzi"}) );
        set("gender", "����" );
        set("age", 20);
   set("long", "����һλ���ֺ��еĸ��ҹ��Ӹ硣\n");       
   set("combat_exp",80000);
   set("str", 10);
   set("per", 22);
   set("chat_chance",30);
   set("chat_msg",({
     "����ҡҡ���ӣ�����ͷ�����������涼��˳�ģ�\n",
     "����ҡҡͷ��̾�˿���˵������ôû��Ư����С�������������أ�\n",
     "��������Զ��˵������˵�����в�����Ů����Щ����Ӧ��ȥ�������ˡ�\n",
     }));
   setup();
   add_money("silver",2);
}

