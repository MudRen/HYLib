inherit NPC;
void create()
{
   set_name("�����",({"ke zhene"}));
   set("gender","����");
   set("long","�����߹�֮��,��ϧ����ǰ���ڷ�˫ɷ��������!\n");
   set("mingwang",90000);
   set("combat_exp",180000);
   set("title","��������");
   
set("age",54);
   set("kee",1800);
   set("max_kee",1800);
set("food",250);
set("water",250);
   set("neili",1800);
   set("max_neili",1800);
   set("force_factor",20);

   set_skill("dodge",180);
   set_skill("force",180);
   set_skill("parry",180);
   set_skill("unarmed",180);
   set_skill("staff",180);

   setup();
   add_money("silver",80);
carry_object(__DIR__"obj/cloth")->wear();
carry_object(__DIR__"obj/tiezhang")->wield();
}
