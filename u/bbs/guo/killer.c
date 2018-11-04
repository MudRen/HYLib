#include <ansi.h>
inherit NPC;

int do_copy(object me);
int do_back(object me);

void create()
{
      string weapon;
        set_name("������", ({ "heiyi ren","ren"}));
        set("gender", "����");
        set("age", random(20) + 25);
        set("str", 23);
        set("con", 26);
        set("int", 20);
        set("dex", 23);
        set("long", "һ�����ź�ɫҹ���µ��ˡ�\n");
        set("combat_exp", 80000 + random(40000)); 
        set("attitude", "friendly");
        set_skill("force", 50);
        set_skill("sword", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set_skill("cuff", 50);
        set_skill("blade", 50);
        set_skill("taizu-quan", 50);
        set_skill("qingmang-jian", 50); 
        map_skill("dodge", "qingmang-jian");
        map_skill("sword", "qingmang-jian");
        map_skill("parry", "qingmang-jian");
        map_skill("blade", "qingmang-jian");
        map_skill("cuff", "taizu-quan");
        prepare_skill("cuff", "taizu-quan");         
        set("max_qi", 450); 
        set("eff_jingli", 400); 
        set("neili", 700); 
        set("max_neili", 700);
        set("jiali", 30);
        weapon = random(2)?"/clone/weapon/gangjian":"/clone/weapon/gangdao";
        setup();
        carry_object(weapon)->wield();
carry_object("/clone/cloth/cloth")->wear();
}
int do_copy(object me)
{
        int i,j;
        object ob;
        ob = this_object();

        i = me->query_skill("dodge",1);
        j = me->query_skill("force",1);
        i = i>j?i:j;
		i = i - random(20);
        if( i < 60) i = 60;
        
        ob->set("combat_exp", (me->query("combat_exp")+random(me->query("combat_exp")))/2);
        ob->set_skill("force", i);
        ob->set_skill("sword", i);
        ob->set_skill("blade", i);
        ob->set_skill("dodge", i);
        ob->set_skill("parry", i);
ob->set_skill("parry", i);
        ob->set_skill("qingmang-jian", i);       
        ob->set_skill("taizu-quan", i); 
ob->set("max_qi",300+me->query("max_qi")*2/3); 
        ob->set("eff_jingli", me->query("eff_jingli")*2/3); 
        ob->set("max_neili",  me->query("max_neili")*2/3); 
        ob->set("jiali", ob->query("force")/6);
        ob->reincarnate(); 
        call_out("do_back", 350,  ob);  
        return 1;
}
int do_back(object me)
{                       
  tell_room(environment(me), me->query("name")+"�Ҵ�ææ���뿪�ˡ�\n", ({me}));	
  destruct(me); 
  return 1;
}
void die()
{
	object corpse;
	mixed killer;
	if( !living(this_object()) ) revive(1);
	else delete_temp("faint_by");
	COMBAT_D->announce(this_object(), "dead");
	if( !(killer = query_temp("last_damage_from")) )
	killer = "Ī�������";
	if( objectp(corpse = CHAR_D->make_corpse(this_object(), killer)) )
	corpse->move(environment());
	set_temp("last_damage_from", "Ī�������");
    corpse->set_temp("must_killby",this_object()->query_temp("must_killby"));
	this_object()->remove_all_killer();
	all_inventory(environment())->remove_killer(this_object());
    destruct(this_object());
}
