inherit NPC;
void create()
{
     set_name("�˷���",({"ren fanzi","fanzi"}));
     set("shen_type",-1);
     set("age",56);
     set("gender","����");
     set("combat_exp",200000);
     set("str",21);
     set("per",16);
     set_skill("unarmed",70);
     set_skill("dodge",70);
     set_skill("parry",70);
     set("inquiry",([
            "С����":"�����Ҽ��϶��ĺ��ӣ����ƶ�ɰ�!\n",
            "kid":"�������ӣ���������꣬�͵�Ƥ�ò���!\n",
            "С��":"û�������⴮���Ϳ޸����У�������û�취!\n",
             ]));
     setup();
     carry_object("/clone/misc/cloth")->wear();
     add_money("silver",30);
}