
inherit NPC;

void create()
{
     set_name("Сӥ",({ "xiao ying","xiao","ying"}) );
     set("race", "Ұ��" );
     set("long", "����һֻ��С�ĳ�ӥ��\n");
     set("verbs",({"bite"}));
     set("limbs",({"ͷ","����"}));
     set("bai_dun_quest_obj2",1);
     setup();

}

void die()
{
   unconcious();
}