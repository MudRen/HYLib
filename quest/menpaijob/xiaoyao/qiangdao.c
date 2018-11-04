// qiangdao.c ǿ��
// lag.2000/3/17

inherit NPC;
#include <ansi.h>
void move();

void create()
{       object me;
        int myskill;
        me=this_player();
        myskill=me->query_skill("force");
        set_name(HIC "��ң����ͽ" NOR, ({ me->query("id")+"-pantu"}));
        set("title",me->query("name")+"���µ�");
        set("gender", "����");
        set("age", 28);
        set("long", "����һ����ң����ͽ��\n");
        
        set("attitude", "peaceful");
        set("qi", me->query("qi")* 4 / 5);
        set("max_qi", me->query("max_qi")* 4 / 5);
        set("jing", me->query("jing")* 4 / 5);
        set("neili", me->query("neili")* 4 / 5);
        set("max_neili", me->query("max_neili")* 4 / 5);
        set("max_jing", me->query("max_jing")* 4 / 5);
        set("str", me->query("str")* 4 / 5);
        set("dex", me->query("dex")* 4 / 5);
        set("per", me->query("per")* 4 / 5);
        set("killer",me->query("id"));
        set("combat_exp", me->query("combat_exp")* 4 / 5);
// ������5������ǿ���Զ��ߣ���������������˵����ѣ�-��ԲSMILE
	set("chat_chance_combat", 30);  
	set("chat_msg_combat", ({
                (: perform_action, "blade.shishiruyi" :),
                (: perform_action, "blade.ruyi" :),
                (: perform_action, "blade.ruyi" :),
                (: perform_action, "dodge.lingbo" :),
                (: perform_action, "dodge.lingbo" :),
                (: exert_function, "strike.zhong" :),                
                (: exert_function, "hand.zhemei" :),                
                (: exert_function, "hand.duo" :),                
                (: exert_function, "strike.lianzhong" :),                
                (: exert_function, "unarmed.lianzhong" :),                
	}) );
             set("chat_chance", 30);
             set("chat_msg", ({
              (: random_move :)
        }) );


        set_skill("hand", myskill * 4 / 5);
        set_skill("dodge", myskill * 4 / 5);
        set_skill("unarmed", myskill* 4 / 5);
        set_skill("parry", myskill* 4 / 5);
        set_skill("force", myskill* 4 / 5);
        set_skill("blade", myskill* 4 / 5);
        set_skill("lingboweibu", myskill* 4 / 5);
        set_skill("ruyi-dao", myskill* 4 / 5);
        set_skill("liuyang-zhang", myskill* 4 / 5);
        set_skill("zhemei-shou", myskill* 4 / 5);
	set_skill("beiming-shengong",myskill* 4 / 5);
	map_skill("unarmed", "liuyang-zhang");
	map_skill("strike", "liuyang-zhang");
	map_skill("hand", "zhemei-shou");
	map_skill("unarmed", "liuyang-zhang");
	map_skill("parry", "ruyi-dao");
	map_skill("blade", "ruyi-dao");
	map_skill("dodge", "lingboweibu");
	map_skill("force", "beiming-shengong");
	prepare_skill("hand","zhemei-shou");
	prepare_skill("strike","liuyang-zhang");	
        set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/armor", 100);
        set_temp("apply/damage", 250);
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/gangdao")->wield();

}

void init()
{
        remove_call_out("leave");
        call_out("leave",60);
}

void leave()
{
        object ob = this_object();
        if (!ob->is_fighting()) {
                message_vision(HIC "��ң����ͽ���·�ߵ��Ӳݣ������ˡ�\n" NOR,this_object());
                destruct(this_object());
                }
        else call_out("leave",30);
}

void unconcious()
{
    die();
}

void die()
{
        object me = this_object()->query_temp("last_damage_from");
        object corpse,zhi;      

if (me)
{
        message_vision(HIR "\n��ң����ͽ���ڵ��ϣ������˼��¾����ˡ�\n" NOR,me);
        message_vision(HIG "\n�����ͽ�������ҵ����߱�ָ����\n" NOR,me);
        if (me->query("kill_xiaoyao") == 1 && this_object()->query_temp("owner/id") == me->query("id")) {
               zhi=new(__DIR__"zhi");
               zhi->set("byname",me->query("name"));
               zhi->move(me);
                me->add("score",2);
                }

        corpse = new("/clone/misc/corpse");
        corpse->set("name",HIW "��ң����ͽ��ʬ��" NOR);
        corpse->set("long","����һ�������޶�������ң����ͽ��\nȻ�������Ѿ����ˣ�ʣ��һ�߳�ª��ʬ�塣\n");
        corpse->move(environment(this_object()));
        corpse->set_max_encumbrance(1000);        
        me->add("MKS", 1);
}
        destruct(this_object());
}

