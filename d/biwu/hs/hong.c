// sample master.c code
// xiake island master.c
#include <ansi.h>
inherit NPC;
//inherit F_MASTER;

void consider();

void create()
{
	set_name("���߹�", ({"hong qigong", "hong", "qigong"}));
	set("title", HIG"��ؤ"NOR);
	set("gender", "����");
	set("age", 75);
set("beggarlvl",9);
	set("long", 
		"������ؤ���ʮ���ΰ������ųơ���ؤ���ĺ��߹���ү�ӡ�\n");
	set("attitude", "peaceful");
        set("class", "beggar");
	
	set("str", 60);
	set("int", 64);
	set("con", 60);
	set("dex", 64);

	set("chat_chance", 1);
	set("chat_msg", ({
		"���߹�̾�˿�����������������ʱ���ٳԵ��ض����ġ��л�������������\n",
		"���߹�˵�������׻�˵�����ڽ��ϡ��������Ͻл��ص��������ݿ�������\n",
		"���߹��૵���������ؤ��ġ�����ʮ���ơ���������Ե����Ʒ�����\n",
	}));
	set("qi", 19000);
	set("max_qi", 19000);
	set("jing", 19400);
	set("max_jing", 19400);
	set("neili", 68000);
	set("max_neili", 68000);
	set("jiali", 500);
	        set_temp("no_kill",1);
	set("combat_exp", 5000000);
	set("score", 500000);
	set("shen", 100000);
	         set("szj/passed",1);
        set("double_attack",1);
        set("breakup", 1);
        set("szj/over500", 1);
        set("jiuyin/full", 1);
        set("jiuyin/shang", 1);
        set("jiuyin/xia", 1);
        set("xlz/hang", 1);
         set_temp("apply/attack", 80);
        set_temp("apply/defense", 80);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
	set_skill("force", 500);             // �����ڹ�
	set_skill("huntian-qigong", 500);    // ��������
	set_skill("unarmed", 500);           // ����ȭ��
	set_skill("xianglong-zhang", 500);   // ����ʮ����
	set_skill("dodge", 500);      	     // ��������
	set_skill("xiaoyaoyou", 450);        // ��ң��
	set_skill("parry", 500);             // �����м�
	set_skill("staff", 500);             // ��������
	set_skill("dagou-bang", 500);        // �򹷰���
	set_skill("begging", 500);           // �л�����
	set_skill("checking", 550);          // ����;˵
	set_skill("training", 550);         // Ԧ����
	
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "dagou-bang");
	map_skill("staff", "dagou-bang");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "staff.ban" :),
                (: perform_action, "staff.zhuang" :),
                (: perform_action, "staff.feng" :),
                (: perform_action, "staff.duo" :),
                (: perform_action, "staff.chan" :),
                (: perform_action, "staff.luanda" :),
                (: perform_action, "staff.wugou" :),                
                (: command("unwield yuzhu zhang") :),
                (: command("wield yuzhu zhang") :),
                (: perform_action, "unarmed.kanglongwuhui" :),                
                (: perform_action, "unarmed.leiting" :),                
                (: perform_action, "unarmed.xianglong" :),                                
                (: perform_action, "dodge.canghaiyixiao" :),                                
        }) );
	setup();
	
    carry_object("/kungfu/class/gaibang/obj/yuzhu_zhang")->wield();
    carry_object("/kungfu/class/gaibang/obj/jiaohuaji");
}

int heal_up()
{
	if( environment() && !is_fighting() ) {
		call_out("leave", 1);
		return 1;
	}
	return ::heal_up() + 1;
}

void leave()
{
	object owner;
	message("vision",HIG"���������\n\n"
		+ name() + HIG"����һ������ʧ�����ˡ�\n" NOR, environment(),
		this_object() );
	destruct(this_object());
}
void unconcious()
{
die();
}
void die()
{
        object ob, me, corpse;
        
        ob = this_object();
        me = query_temp("last_damage_from");
        if (!me) return;
if (me==ob)
{
me->set("qi",1);
me->set("eff_qi",1);
me->set("jing",1);
me->set("eff_jing",1);
}

if (!me->query_skill("jiuyin-zhengong",1)
&& me->query_temp("hsljn"))
{
me->set_temp("hslj/2",1);
message("channel:chat", "����ɽ�۽�����˵"+me->name() + "�����"+ob->query("title")+ob->query("name")+"!"NOR"\n", users());
        me->add("combat_exp",300);
        me->add("potential",100);
}
        destruct(ob);
        return;
}
