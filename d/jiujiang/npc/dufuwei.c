
inherit NPC;

void create()
{
   set_name("�ŷ���",({ "du fuwei","du"}) );
        set("gender", "����" );
        set("age", 42);
   set("long", "���ǽ���������ͷ�ϴ󣬾�˵��Ҳ�ǡ�\n"+
               "���ٺ���������常�����������ѹ�˳��\n"+
               "������������Ķ������׺ݿ��ǽ��������ġ�\n");
       
   set("combat_exp",800000);
   set("str", 28);
   set("per", 20);
   set("attitude", "peaceful");
   set_skill("unarmed",270);
   set_skill("dodge",270);
   set_skill("parry",270);
   set_skill("force",270);
   set_skill("strike",270);
   set_skill("cuff",270);

   set("max_qi",3000);
   set("max_jing",3000);
   set("max_neili",3000);
   set("force",3000);
   set("bellicosity",3000);
   set("inquiry",([
     "����":"��С�ӵĵ���ȷʵ�ܸߣ������Ѳ������Ķ����ˣ�\n",
     "������":"����Ϊ�˺ܺã���֪�����������������ӡ�\n",
     ]));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

