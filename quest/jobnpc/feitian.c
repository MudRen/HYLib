// jianxin.c
// ����(diabio)��Ȩ����
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int ask_fail();
string  ask_job();
string ask_me();
string ask_dao();
string ask_give();
string *nm1_jp =({
"ɽ��","����","����","��","����","����","��֥","��","��Ұ","ɽ��",
"��ľ","�ڲ�","С��","����","����","ǳ��","����","��ĩ","����","���",
"����","����","����",
});

string *id_jp =({
"shanben","guitian","zisan","dadao","songxia","hengtian","dongzhi","houben","chuangye","shankou",
"lingmu","gangcang","xiaodao","jinshang","annai","qiantian","zuoteng","guangmu","dazhu","dachun",
"bozuo","fugang","dongxiang",
});    
    
string *nm2_jp =({
"̫��","����","����","����","����","ʮһ��","ʮ����","��ʮ��","����",
"����","Ӣ��","ұ��","����","����","���","��һ","Ӣ��","��ʯ","�弪",
"һҶ","�ӹ�","����","����","��԰","��ˮ","���","���","Т��","ï",
"��","��","����","����","����","ɽ��","�ζ�",
});
void create()
{
   int i = random(sizeof(nm1_jp));
    set_name(nm1_jp[i]+nm2_jp[random(sizeof(nm2_jp))], ({id_jp[i]}));
        set("nickname", HIW"�ε��R"NOR);
              set("title", HIR"ǰά��־ʿ"NOR);
        set("gender", "����");
        set("age", 26);
        set("attitude", "peaceful");
        set("str", 47);
        set("int", 42);
        set("con", 45);
        set("per", 45);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.break" :),
                (: perform_action, "unarmed.qin" :),
                (: perform_action, "unarmed.niu" :),
                (: perform_action, "unarmed.yaozhan" :),
                (: perform_action, "blade.chaodao" :),
                (: perform_action, "blade.tianxiang" :),
                (: perform_action, "blade.longlianda" :),
                (: perform_action, "blade.suodi" :),
                (: perform_action, "blade.jiu" :),
                (: perform_action, "unarmed.sanchong" :),
        }));
        set("qi",10000);
        set("eff_jing",5000);
        set("jing",5000);
        set("eff_qi",10000);
        set("max_qi",10000);
        set("max_jing",5000);
        set("neili", 10000);
        set("max_neili", 15000);
        set("jiali", 50);
        set("shen",5000000);

        set("combat_exp", 3000000);

        set_skill("unarmed", 250);
        set_skill("force", 260);
        set_skill("parry", 280);
        set_skill("dodge", 250);
                set_skill("cuff",200);
        set_skill("blade", 300);
        set_skill("literate", 250);
        set_skill("xuanhualiu-quanfa", 250);
        set_skill("feitian-yujianliu",300);
        set_skill("wuxing-dun", 250);
        set_skill("shayi-xinfa", 320);
        set_skill("shayi", 300);
//        set_skill("bearart", 1100);
       

        map_skill("force", "shayi-xinfa");
        map_skill("parry", "feitian-yujianliu");
        map_skill("blade", "feitian-yujianliu");
        map_skill("dodge", "wuxing-dun");
        map_skill("unarmed", "xuanhualiu-quanfa");

        create_family("����������", 6, "����");
        set("book_count",1);
        set("inquiry", ([
           "���е�": (: ask_me :),
           "����": (: ask_dao :),
           "���е����": (: ask_give :),
           "ʮ��":     "����־־���ټ���ʮ����֡�",
           "��ͷ����": "���Ǳ��ų����������������߽���,��û����ʵ�ĸ��ױ����׳��ԡ���������(accept test)��\n",
           "���е�": (: ask_me :),
   	    "ά��"  : (: ask_job :),
	    "shirenjob"  : (: ask_job :),
            "jobfail" : (: ask_fail() :),
            "����ʧ��" : (: ask_fail() :),
            ]));
        setup();
      carry_object("/clone/cloth/cloth")->wear();
      carry_object("/d/feitian/npc/obj/shoes")->wear();
          carry_object("/d/feitian/npc/obj/nirendao")->wield();
}


void die()
{
int i,pot,exp;
	object killer;
	exp= random(80)+80;
	pot= exp/3;
	if(objectp(killer = query_temp("last_damage_from")))
        	tell_object(killer,"�㱻������\n"+chinese_number(exp)+"��ʵս����\n"
		+chinese_number(pot)+"��Ǳ��\n");
if (killer)
{
	killer->add("combat_exp",exp);
	killer->add("potential",pot);
}
	::die();

return ;
}