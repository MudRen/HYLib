 // heaven_soldier.c
#include <ansi.h> 
inherit NPC;
//void backattack();
void create()
{ 
        set_name("����", ({ "shiwei", "guard" }) );
        set("long", "����һλ��͢�Ĵ������������ӳ�͢���ٵ�ָ�ӡ�\n");
        set("attitude", "friendly");
//      set("vendetta_mark","authority");
        set("title","��͢���� ��Ʒ��������");
        set("max_atman", 100);
        set("atman", 100);
        set("max_mana", 100);
        set("mana", 100); 
        set("combat_exp", 100000);
        set_skill("blade", 70);
        set_skill("parry", 70);
        set_skill("dodge", 70);
        setup(); 
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/gangdao")->wield();
} 
void leave()
{
        object owner,*pros;
        message("vision",
                 name() + "����������ʧ�����ˡ�\n" , environment(),
                this_object() );
        if(objectp(owner=this_object()->query("possessed")))
        {
                owner->add_temp("guard_count",-1);
                pros = owner->query_temp("protectors");
                   pros -= ({ this_object() });
                owner->set_temp("protectors",pros);
        }
        destruct(this_object());
}  
void init()
{
        ::init();
        if( !query_heart_beat(this_object()) ) set_heart_beat(1);
        add_action("do_kill","kill");
        add_action("do_dismiss","dismiss");     
}  
void heart_beat()
{
        object leader;
        
        ::heart_beat();
        
        if(query_temp("is_unconcious")||is_busy())
                return ;
        if(query("possessed"))
        {
                leader=query("possessed");
                if(environment(leader)!=environment()&&(!leader->is_ghost()))
                {
                        message_vision("$N�Ҵ���ȥ��\n",this_object());
                        this_object()->move(environment(leader));
                        message_vision("$N���˹�����\n",this_object());
                        delete("leave_room");
                }
        }
        
        else
        {
                if(!query("leave_room"))
                        set("leave_room",1);
                else
                        add("leave_room",1);
                if(query("leave_room")==5)
                        leave();
   }
} 
int do_dismiss(string arg)
{
        object who,obj;
        
        if(!arg) return 0;
        if(!obj=present(arg,environment()))
                return 0;
        if(obj!=this_object()) return 0;
        who=this_player();
        if(who->query("sen")<200)
        {
                tell_object(who,"������񲻹����޷��Ա�ʿ�����\n");
                return 1;
        }
        if(who!=query("possessed")) return 0;
        who->add("sen",-200);
        message_vision("$N��$n˵���������ﲻ��Ҫ���ˣ���ȥ�ɡ�������\n",who,obj);
        obj->ccommand("inn "+who->query("id"));
        call_out("leave",1);
        return 1;
}  
int do_kill(string arg)
{
        object victim,who;
        
        who=this_player();
        if(!arg) return 0;
        if(environment()->query("no_fight"))
                return 0;
        victim=present(arg,environment());
        if(!victim) return 0;
        if(victim==who) return 0;
        if(victim->query("possessed")==who)
        {
                tell_object(who,"�㲻��ɱ�Լ��Ļ����������»�������µġ�\n");
                return 1;
        }
        if(victim==query("possessed")||victim->query("possessed")==query("possessed"))
   if(who->query("vendetta_mark")!="authority")
        {
                message_vision("$N�ȵ������󵨷�ͽ����Ȼ�ҼӺ���͢���٣�����\n",this_object());
                kill_ob(who);
        }
        if(who==query("possessed")&&victim->query("vendetta_mark")!="authority")
        {
                message_vision("$N��"+victim->query("name")+"�ȵ������󵨷�ͽ�������������־��ܣ���\n",this_object());
                kill_ob(victim);
        }
        return 0;
} 
string *lname = ({
"��","Ǯ","��","��","��","��","֣","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","ʩ","��",
"��","��","��","��","��","κ","��","��","��","л","��","��","��","ˮ","�","��","��","��","��","��","��","��","��","��",
"³","Τ","��","��","��","��","��","��","ɵ","��","Ԭ","��","��","��","ʷ","��","��","��","�","Ѧ","��","��","��","��",
"��","��","��","��","��","��","��","��","��","��","ʱ","��","Ƥ","��","��","��","��","��","Ԫ","��","��","ӯ","ƽ","��",
"��","��","Ф","��","Ҧ","��","տ","��","��","ë","��","��","��","��","��","��","��","��","��","��","̸","��","é","��",
"��","��","��","��","��","ף","��","��","��","��","��","��","��","��","֧","��","��","��","¬","Ӣ","��","��","˾��",
"�Ϲ�","ŷ��","�ĺ�","���","����","����","����","�ʸ�","ξ��","����","�̨","����",
"����","���","����","����","̫��","����","����","����","ԯ��","���","����","����",
"����","Ļ��","˾ͽ","ʦ��","��","��ľ","����","����","���","����","����","����",
"��ֺ","�й�","�׸�","����","����","�ַ�","��۳","Ϳ��","��ǧ","����","����","�Ϲ�",
"����","�麣","����","΢��","��","˧","��","��","��","��","��","��","����","����","����","����",
    }); 
void invocation(object who, int level)
{
        int i;
        object *enemy,*pros;
        
        set_name(lname[random(sizeof(lname))]+"����",({ "shiwei", "guard" }) );
        set("str",30+random(level/7));
        set("agi",30+random(level/7));
        set("cor",30+random(30));
        set("max_qi",1000+random(level*level/30));
        set("eff_qi",query("max_qi"));
        set("kee",query("max_qi"));
        set_skill("blade", 70 + random(level/2));
        set_skill("parry", 70 + random(level/2));
        set_skill("dodge", 70 + random(level/2));
   set_skill("move", 70 + random(level/2));
        set_skill("shortsong-blade",50+random(level/4));
        set_skill("fall-steps",50+random(level/2)); 
        
        set("combat_exp", 100000 + level*level*10+random(level*level*level/16));
        set("max_force",1000+random(level*level/10));
        set("force",query("max_force"));
        set("force_factor",50+random(level/8));
        set("possessed",who);
        pros = who->query_temp("protectors");
        if(sizeof(pros))
                pros += ({ this_object() });
        else
                pros = ({ this_object() });
        who->set_temp("protectors",pros);
}
/*
void backattack()
{
        int i;
        object owner, *enemy;
        if(objectp(owner=this_object()->query("possessed")))
        {
                enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        owner->kill_ob(enemy[i]);
                        enemy[i]->kill_ob(owner);
                }
        } 
        } 
}
*/
void die()
{
        object owner,*pros;
        if(objectp(owner=this_object()->query("possessed")))
        {
                owner->add_temp("guard_count",-1);
                pros = owner->query_temp("protectors");
                        pros -= ({ this_object() });
                owner->set_temp("protectors",pros);
        }
        ::die();
} 
/*
        message("vision",
                 name() + "�ȵ����󵨣����Һͳ�͢���ٹ���ȥ��\n"NOR,
                environment(), this_object() );
        enemy = who->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        kill_ob(enemy[i]);
                        if( userp(enemy[i]) ) enemy[i]->fight_ob(this_object());
                        else enemy[i]->kill_ob(this_object());
                }
        }
*/ 
int attack()
{
        object opponent,owner;
        int exp,extra;           
        opponent = select_opponent();
        if(objectp(opponent)) {
                set_temp("last_opponent", opponent);
        owner=query("possessed");
        if(opponent==owner)
        {
                this_object()->ccommand("ah");
                message_vision("$N��$n˵��������֪�Ǵ��ˣ�С�˸ղŶ��ð���ˣ��������ˡ���\n",this_object(),owner);
                this_object()->ccommand("escape");
                leave();
                return 1;
        }
        
        exp=opponent->query("combat_exp");                              
        extra=owner->query_skill("leadership",1);
        if(random(extra/10) ) 
           COMBAT_D->fight(this_object(), opponent);
        else 
                if(random(exp)>extra*extra*extra)
                {
                        message_vision("$N�����������������ƴ󣬻��Ǳ���Ϊ�Ȱɡ���\n",this_object());
                        this_object()->ccommand("escape");
                        leave();
                }
        return 1;
        } else
                return 0;
}  
