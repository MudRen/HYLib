#include <ansi.h>
inherit NPC;

int do_copy(object me,int maxpot,int type);
// zhang.c ������
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
string *name_3 = ({
"����","��ӥ","�ٶ�","��ȭ","����","��Ӱ","����","����",
"����","ѪӰ","��ɱ","���","����"
});

void create()
{
      string weapon;
   int i = random(sizeof(nm1_jp));
    set_name(nm1_jp[i]+nm2_jp[random(sizeof(nm2_jp))], ({id_jp[i]}));
set("title", HIR"ʮ��" + name_3[random(sizeof(name_3))] + "ɱ��");
	set("per", 35);
        set("age", random(20) + 20);
        set("str", 33);
        set("con", 36);
        set("int", 30);
        set("dex", 33);
        set("combat_exp", 80000 + random(40000)); 
        set("attitude", "friendly");
	set_skill("taiji-shengong", 300);
	set_skill("dodge", 150);
	set_skill("tiyunzong", 300);
	set_skill("unarmed", 200);
	set_skill("taiji-quan", 300);
	set_skill("parry", 200);
	set_skill("sword", 200);
	set_skill("array",100);
	set_skill("taoism", 250);
	set_skill("blade", 150);
	set_skill("shiren-jianfa", 150);
	set_skill("shiren-quanfa", 150);
	set_skill("wuxing-dun", 150);
	map_skill("unarmed", "shiren-quanfa");
	map_skill("parry", "shiren-jianfa");
	map_skill("blade", "shiren-jianfa");
	map_skill("dodge", "wuxing-dun");
	
	map_skill("force", "taiji-shengong");

        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 150);
        set("eff_qi", 4500); 
        set("qi", 4500); 
        set("max_qi", 4500); 
        set("eff_jing", 4500); 
        set("jing", 4500); 
        set("max_jing", 4500); 
        set("eff_jingli", 4000); 
        set("neili", 5000); 
        set("max_neili", 5000);

        set("jiali", 30);
        weapon = random(2)?"/quest/weiguo/japan/obj/japanblade":"/quest/weiguo/japan/obj/japanblade";
        setup();
        carry_object(weapon)->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

int do_copy(object me,int maxpot,int type)
{
        int i,j;
        object ob;
        ob = this_object();
if (!me->query_skill("force"))
i=10;
else      i=me->query_skill("force");
//        if(type==1)
//		i = i - random(20);
//		else  
//	    i = i +10+ random(10);
//        if( i < 100) i = 100;
        
        ob->set("combat_exp", (me->query("combat_exp")*3/4));
        
        ob->set_skill("force", i*1/2);
        ob->set_skill("sword", i*1/2);
        ob->set_skill("unarmed", i*1/2);
        ob->set_skill("cuff",  i*1/2);
	ob->set_skill("blade", i*1/2);
        ob->set_skill("dodge", i*1/2);
        ob->set_skill("parry", i*1/2);
        ob->set_skill("taiji-shengong", i*1/2);       
        ob->set_skill("wuxing-dun", i*1/2); 
        ob->set_skill("shiren-jianfa", i*1/2); 
        ob->set_skill("shiren-quanfa", i*1/2);         
        set_skill("taiji-shengong",i*1/2);
ob->set("jing",me->query("max_jing"));
ob->set("eff_jing",me->query("max_jing"));
ob->set("max_jing",me->query("max_jing"));
ob->set("qi",me->query("max_qi"));
ob->set("eff_qi",me->query("max_qi"));
ob->set("max_qi",me->query("max_qi"));
if (random(2)==1)	
ob->map_skill("parry", "shiren-jianfa");
else
ob->map_skill("parry", "shiren-quanfa");
if (random(10)>8)
{
        ob->set_skill("force", i*3/4);
        ob->set_skill("sword", i*3/4);
        ob->set_skill("unarmed", i*3/4);
        ob->set_skill("cuff",  i*3/4);
	ob->set_skill("blade", i*3/4);
        ob->set_skill("dodge", i*3/4);
        ob->set_skill("parry", i*3/4);
        ob->set_skill("taiji-shengong", i*3/4);       
        ob->set_skill("shiren-jianfa", i*3/4); 
        ob->set_skill("shiren-quanfa", i*3/4); 
        ob->set_skill("wuxing-dun", i*3/4);         
        set_skill("taiji-shengong",i*3/4);
}
        ob->set("eff_jingli", me->query("eff_jingli")*1/2); 
        ob->set("jiali", i/6);
	ob->set("max_qi",  me->query("qi")*2/3); 
        ob->set("eff_jingli", me->query("eff_jingli")*2/3); 
        ob->set("max_neili", me->query("max_neili")*2/3); 
        ob->set("jiali", i/10);
        if(type==3)
		{ob->set("max_qi",     me->query("qi")*2/3);
		 ob->set("max_neili",  me->query("max_neili")*2/3); 
		}
		if(type==2)
        ob->set("max_qi",     me->query("qi")*2/3); 
		ob->reincarnate(); 
        ob->set("qi",ob->query("max_qi")*2/3);
        ob->set("neili",ob->query("max_neili")*2/3);
        ob->set("qi",me->query("max_qi"));
        ob->set("eff_qi",me->query("max_qi"));
        ob->set("max_qi",me->query("max_qi"));        
        ob->set("neili",me->query("max_neili"));
        ob->set("max_neili",me->query("max_neili"));
        ob->set("jing",me->query("max_jing"));
        ob->set("eff_jing",me->query("max_jing"));
        ob->set("max_jing",me->query("max_jing"));

}
void die()
{
int i,pot,exp;
	object killer;
	exp= random(160)+80;
	pot= exp*2/3;
	if(!objectp(killer = query_temp("last_damage_from")))
	return;

	if(objectp(killer = query_temp("last_damage_from"))
	&& killer->query_temp("fthwjob")
	&& this_object()->query("usename")==killer->query("name"))
        	tell_object(killer,"�㱻������\n"+chinese_number(exp)+"��ʵս����\n"
		+chinese_number(pot)+"��Ǳ��\n");
if (killer && killer->query_temp("fthwjob")
&& this_object()->query("usename")==killer->query("name"))
{
	killer->add("combat_exp",exp);
	killer->add("potential",pot);
}
	::die();

return ;
}
void init()
{
        remove_call_out("leave");
        call_out("leave",120);
}

void leave()
{
        object ob = this_object();
        if (!ob->is_fighting()) {
                message_vision(this_object()->query("name") + "���·�ߵ��Ӳݣ������ˡ�\n" NOR,this_object());
                destruct(this_object());
                }
        else call_out("leave",30);
}