
inherit NPC;

void create()
{
     set_name("��Ѫ����",({ "hanxue baoma","ma","baoma","horse"}) );
     set("race", "Ұ��" );
     set("long", "����һֻ��Ѫ����\n");
     set("verbs",({"hoof"}));
     set("limbs",({"ͷ","����"}));
     set("perform_quest_kun_obj",1);
     setup();

}

void die()
{
   unconcious();
}

int set_status(object ob)
{
  set("owner_ob",ob);
  set("long","����һֻ��Ѫ������˵������Ѿ���"+ob->name()+"��׽������\n");
  return 1;
}