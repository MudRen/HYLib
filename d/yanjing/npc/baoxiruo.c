inherit NPC;
void create()
{
   set_name("��ϧ��",({"bao xiruo"}));
   set("gender","Ů��");
   set("long","���ڵ�����,�����ٰ�ţ�Ҵ�����ɩ��!\n");
   set("mingwang",6000);
   set("combat_exp",6000);
   set("title","����");
   
set("per",30);
set("age",38);
   set("qi",500);
   set("max_qi",500);
set("food",250);
set("water",250);
   set("neili",100);
   set("max_neili",100);
   set("force_neili",10);

   set_skill("dodge",20);
   set_skill("force",20);
   set_skill("parry",20);
   set_skill("unarmed",20);
   set_skill("club",30);
   set_skill("literate",20);

   set("inquiry",([
   "������":"����,��֪��?��ϧ��������ʮ������!\n",
   "�￵":"�⼸�첻֪����,�ϰ�����Ժ��!\n",
   "��ǹ":"�����ɷ�����������,�ɲ��ܸ���.\n",
  ]));
   setup();
   add_money("silver",6);
carry_object(__DIR__"obj/skirt")->wear();
carry_object(__DIR__"obj/haltspear");
}
