inherit NPC;
int give_food();
void create()
{
   set_name("��ɽɩ",({"sansao","saozi","woman"}));
   set("gender","Ů��");
   set("shen_type",1);
   set("age",32);
   set("combat_exp",30000);
   set("long","��ɽɩ���ĺܺ�,��������˵Ļ�,����
����ҪЩ�Ե�(ask sansao about eat).\n");
  
   set_skill("unarmed",150);
   set_skill("dodge",150);
   set_skill("parry",150);
   set_skill("literate",130);
   set_skill("force",130);

   set("inquiry",([
     "��":(:give_food:),
     "eat":(:give_food:),
     ]));
  setup();
carry_object("/clone/misc/cloth")->wear();
add_money("coin",random(50));
}
int give_food()
{
  object ob;
  ob=this_player();
  if (ob->query("mingwang")<0)  {
       command("say �������ͷ��Ըι��,Ҳ�������˳�.\n");
       return 1;
            }
  else command("say ���˰�,�����ͷ������.\n");
   new("/d/sandboy/obj/mantou")->move(this_object());
  command("give mantou to "+ob->query("id"));
  return 1;
}