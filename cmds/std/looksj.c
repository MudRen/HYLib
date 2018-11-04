// look.c

#include <room.h>
#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;

int look_room(object me, object env, int night);
int look_item(object me, object obj);
int look_living(object me, object obj);
int look_room_item(object me, string arg);
string getper(object obj);
string tough_level(int power, int hide_level);
string gettof(object obj);
string getdam(object obj);
string getatt(object obj);
string getdef(object obj);
string getdog(object obj);
void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        object obj;
        int result;
if (me)
return notify_fail("���ָ��ֻ����ϵͳִ�С�\n");
        if( !arg ) result = look_room(me, environment(me), NATURE_D->is_night());
        else if( (obj = present(arg, me)) || (obj = present(arg, environment(me)))) {
                if( obj->is_character() ) result = look_living(me, obj);
                else result = look_item(me, obj);
        } else result = look_room_item(me, arg);

        return result;
}

int look_room(object me, object env, int night)
{
        int i;
        object *inv;
        mapping exits;
        string str, *dirs;

        if( !env ) {
                write("������ܻ����ɵ�һƬ��ʲôҲû�С�\n");
                return 1;
        }
        
        str = env->query("long");
        // night ^_^ , added by snowman@SJ
        
        if(env->query("no_light")
           && !env->query_night_light()
           && random(me->query_con()) < 35){
                if(env->query("night_long")) str = env->query("night_long");
                else str = "����һƬ��ڣ�����Ȼ�������۾���ϸ�ۿ����ɻ��ǿ��������Χ��\n"+ 
                           "���һ�ж��������ںڰ�֮�У����ֲ�����ָ... \n";
                }
                
        else if(env->query("outdoors") && night 
           && !env->query_night_light()
           && random(me->query_con()) < 35){
                if(env->query("night_long")) str = env->query("night_long");
                else str = "ҹ���ˣ�����Ȼ�������۾���ϸ�ۿ����ɻ��ǿ��������Χ�����\n"+
                           "һ�ж���ҹɫ�����֣������µĵ�·��ģ��������... \n";
                }      
                     
        str = sprintf( "%s - %s\n    %s%s",
                env->query("short"),
                wizardp(me)? file_name(env): "",
                str,
                env->query("outdoors")? NATURE_D->outdoor_room_description() : "" );

        if( mapp(exits = env->query("exits")) ) {
                dirs = sort_array(keys(exits), 1);
                for(i=0; i<sizeof(dirs); i++)
                        if( (int)env->query_door(dirs[i], "status") & DOOR_CLOSED )
                                dirs[i] = 0;
                dirs -= ({ 0 });
                if( sizeof(dirs)==0 )
                        str += "    ����û���κ����Եĳ�·��\n";
                        
                // night ^_^ , added by snowman@SJ
                else if((env->query("outdoors") || env->query("no_light")) 
                        && night && !env->query_night_light()
                        && random(me->query_con()) < 35){
                        i = random(sizeof(dirs));
                        if( random(me->query_con()) < 10) i = 0;
                        else if( random(me->query_con()) < 20) i = 1;
                        if( i <= 0 )
                                str += "    ���￴�����κ����Եĳ�·��\n";
                        else if( i == 1 )
                                str += "    ���￴�ü���Ψһ������ " + BOLD + dirs[i-1] + NOR + "��\n";
                        else str += sprintf("    ���￴����ĳ����� " + BOLD + "%s" + NOR + "��\n", implode(dirs[1..i], "��"));
                        }
                // hehehe.....
                
                else if( sizeof(dirs)==1 )
                        str += "    ����Ψһ�ĳ����� " + BOLD + dirs[0] + NOR + "��\n";
                        
                else    str += sprintf("    �������Եĳ����� " + BOLD + "%s" + NOR + " �� " + BOLD + "%s" + NOR + "��\n",
                                implode(dirs[0..sizeof(dirs)-2], "��"), dirs[sizeof(dirs)-1]);
                        
        }
//      str += env->door_description();

        inv = all_inventory(env);
        for(i=0; i<sizeof(inv); i++) {
                if( inv[i]==me ) continue;
                if( !me->visible(inv[i]) ) continue;
                
                // night.
                if((env->query("outdoors") || env->query("no_light")) 
                   && night 
                   && !env->query_night_light() 
                   && random(me->query_con()) < 35 
                   && !inv[i]->is_character()) continue;   
                // hehehehehehe.....   
                str += "  " + inv[i]->short() + "\n";
        }

        write(str);
        return 1;
}

int look_item(object me, object obj)
{
        mixed *inv;
        string prep;

        write(obj->long());
        inv = all_inventory(obj);
        if( !obj->is_closed() && sizeof(inv)) {
                switch( (string)obj->query("prep") ) {
                        case "on":
                                prep = "��";
                                break;
                        case "under":
                                prep = "��";
                                break;
                        case "behind":
                                prep = "��";
                                break;
                        case "inside":
                                prep = "��";
                                break;
                        default:
                                prep = "��";
                                break;
                        }
                inv = map_array(inv, "inventory_look", this_object() );
                message("vision", sprintf("%s���У�\n  %s\n", prep,
                        implode(inv, "\n  ") ), me);
        }
        return 1;
}

string getper(object obj)
{
        int per, age;

        string str;

        per = obj->query_per();
        age = obj->query("age");
        
        if ((string) obj->query("gender") == "Ů��"){
            if (per >= 40) str = "�������ף����޾��ף�ò������ʤ���֣�\n";
            else if (per >= 37){
                      if(obj->max_food_capacity() > 320)
                           str = "פ����Ϳһ��죬����һЦ��������\n";
                      else str = "�������ף�������࣬���续�����ɣ�\n";
                      }
            else if (per >= 33){
                      if(obj->max_food_capacity() > 320)
                           str = "��ò���������ʸ��ţ������˼����ӣ�\n";
                      else str = "��ò������毻���ˮ�������˼����ӣ�\n";
                      }
            else if (per >= 30){
                      if(obj->max_food_capacity() > 320)
                           str = "�������裬����ˮ�ӣ���ò������\n";
                      else str = "��ۼ���ף�һЦ��ǣ���Ц�����\n";
                      }
            else if (per >= 27) str = "�߻����£��������ɣ�\n";
            else if (per >= 24) str = "������ò�����Ľ��Σ�\n";
            else if (per >= 20) str = "�������ˣ��м�����ɫ��\n";
            else if (per >= 17) str = "��òƽӹ������һ�㡣\n";
            else if (per >= 14) str = "���Ųλ��ò�����Ρ�\n";
            else str = "һ����Ϳ������������\n";
        } else {
            if (per >= 40) str = "Ӣ�˲�����һ���˲ţ���Ϊ����������һ�ˣ�\n";
            else if (per >= 37) str = "�����ٷ磬�������Σ����ƾ������У�\n";
            else if (per >= 33) str = "���㿡�ţ���ò�Ƿ��������������\n";
            else if (per >= 30){
                      if(obj->max_food_capacity() < 160)
                             str = "ò����Ů�����������������磡\n";
                      else  str = "ò���˰����ݱ������Ǳ����ã�\n";
                      }
            else if (per >= 27) str = "��ò���ڣ��������У�\n";
            else if (per >= 24) str = "Ӣ�����������ʷǷ���\n";
            else if (per >= 20) str = "��ٶ�������òƽƽ��\n";
            else if (per >= 17) str = "��ٲ������������ӡ�\n";
            else if (per >= 14) str = "ţ��¿������Ŀ������\n";
            else str = "�����׹��·����˽䷵�꣡\n";
        }
        return "����" + str;
}

string gettof(object ob)
{
        object weapon;
        string skill_type;
        int attack_points, hide_level;
        mapping prepare;

        if( objectp(weapon = ob->query_temp("weapon")) )
        {
                skill_type = weapon->query("skill_type");
        }
        else
        {
                prepare = ob->query_skill_prepare();
                if (!sizeof(prepare)) skill_type = "unarmed";
                else skill_type = keys(prepare)[0];
        }

        attack_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK);
        
        if( intp(hide_level = ob->query_temp("hide_level")) && hide_level > 0)
               return tough_level(attack_points/100, hide_level);
        return tough_level(attack_points/100, 0);
}

string getatt(object ob)
{
        object weapon;
        string skill_type;
        int attack_points, hide_level;
        mapping prepare;

        if( objectp(weapon = ob->query_temp("weapon")) )
        {
                skill_type = weapon->query("skill_type");
        }
        else
        {
                prepare = ob->query_skill_prepare();
                if (!sizeof(prepare)) skill_type = "unarmed";
                else skill_type = keys(prepare)[0];
        }

attack_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK);         
        if( intp(hide_level = ob->query_temp("hide_level")) && hide_level > 0)
               return tough_level(attack_points/200, hide_level);
        return tough_level(attack_points/200, 0);
}

string getdef(object ob)
{
        object weapon;
        string skill_type;
        int attack_points, hide_level;
        mapping prepare;

        if( objectp(weapon = ob->query_temp("weapon")) )
        {
                skill_type = weapon->query("skill_type");
        }
        else
        {
                prepare = ob->query_skill_prepare();
                if (!sizeof(prepare)) skill_type = "unarmed";
                else skill_type = keys(prepare)[0];
        }

attack_points = COMBAT_D->skill_power(ob, "parry", SKILL_USAGE_DEFENSE); 
        if( intp(hide_level = ob->query_temp("hide_level")) && hide_level > 0)
               return tough_level(attack_points/200, hide_level);
        return tough_level(attack_points/200, 0);
}
string getdog(object ob)
{
        object weapon;
        string skill_type;
        int attack_points, hide_level;
        mapping prepare;

        if( objectp(weapon = ob->query_temp("weapon")) )
        {
                skill_type = weapon->query("skill_type");
        }
        else
        {
                prepare = ob->query_skill_prepare();
                if (!sizeof(prepare)) skill_type = "unarmed";
                else skill_type = keys(prepare)[0];
        }

attack_points = COMBAT_D->skill_power(ob, "dodge", SKILL_USAGE_DEFENSE); 
        if( intp(hide_level = ob->query_temp("hide_level")) && hide_level > 0)
               return tough_level(attack_points/200, hide_level);
        return tough_level(attack_points/200, 0);
}
int look_living(object me, object obj)
{
        int age;
        string str, pro;
        mixed *inv;
        mapping my_fam, fam;

        if( me!=obj && obj->visible(me))
                message("vision", me->name() + "�������㿴����֪����Щʲô���⡣\n", obj);

        inv = explode(obj->long(), "\n");
        str = implode(inv[0..20], "\n")+"\n";
        if (sizeof(inv) > 21) str += "�˴�ɾȥ"+chinese_number(sizeof(inv)-21)+"�С�\n";

        pro = (obj==me) ? gender_self(obj->query("gender")) : gender_pronoun(obj->query("gender"));

        if (!obj->query_temp("apply/long")) {
                if( (string)obj->query("race")=="����"
                        && intp(age = obj->query("age")) ) {
                        if (obj->query_skill("beauty") > 30) age -= (obj->query_skill("beauty")-30)/5;
                        if (age < 10)
                                str += sprintf("%s����������ʮ�꣬", pro);
                        else
                                str += sprintf("%s������Լ%s���꣬", pro, chinese_number(age / 10 * 10));
                        if (wizardp(me) || obj->query("age") >= 16) str +=getper(obj);
/*
                                                //��ʱȡ������ʦ�������ơ���ҷ�ӳ̫��
                        if (wizardp(me)) {
*/
                                str +=sprintf("%s�����տ���ȥ", pro);
                                str +=gettof(obj);
                                str +="��";
                                str +=sprintf("�����ƺ�");
                                str +=getdam(obj);
                                str += sprintf("��\n");
                        /*}*/
                }
                // If we both has family, check if we have any relations.
                if( obj!=me
                &&      mapp(fam = obj->query("family"))
                &&      mapp(my_fam = me->query("family")) 
                &&      fam["family_name"] == my_fam["family_name"] ) {
                
                        if( fam["generation"]==my_fam["generation"] ) {
                                if( (string)obj->query("gender") == "Ů��")
                                        str += sprintf( pro + "�����%s%s��\n",
                                                my_fam["master_id"] == fam["master_id"] ? "": "ͬ��",
                                                my_fam["enter_time"] > fam["enter_time"] ? "ʦ��": "ʦ��");
                                else
                                        str += sprintf( pro + "�����%s%s��\n",
                                                my_fam["master_id"] == fam["master_id"] ? "": "ͬ��",
                                                my_fam["enter_time"] > fam["enter_time"] ? "ʦ��": "ʦ��");
                        } else if( fam["generation"] < my_fam["generation"] ) {
                                if( my_fam["master_id"] == obj->query("id") )
                                        str += pro + "�����ʦ����\n";
                                else if( my_fam["generation"] - fam["generation"] > 1 )
                                        str += pro + "�����ͬ�ų�����\n";
                                else if( fam["enter_time"] < my_fam["enter_time"] )
                                        str += pro + "�����ʦ����\n";
                                else
                                        str += pro + "�����ʦ�塣\n";
                        } else {
                                if( fam["generation"] - my_fam["generation"] > 1 )
                                        str += pro + "�����ͬ������\n";
                                else if( fam["master_id"] == me->query("id") )
                                        str += pro + "����ĵ��ӡ�\n";
                                else
                                        str += pro + "�����ʦֶ��\n";
                        }
                }
        
                if (userp(obj) && obj->query("id") == me->query("marry/id"))
                        str += pro + "�����"
                                + (obj->query("gender") == "Ů��"?"����":"�ɷ�")
                                + "��\n";
                if (obj->query_temp("marry") == me)
                        str += pro + "�����δ��"
                        + (obj->query("gender") == "Ů��"?"��":"��") + "��\n";
        }

        if( obj->query("max_qi") )
                        str += pro + COMBAT_D->eff_status_msg((int)obj->query("eff_qi") * 100 / (int)obj->query("max_qi")) + "\n";

        inv = all_inventory(obj);
        if( sizeof(inv) ) {
                inv = map_array(inv, "inventory_look", this_object(), obj->is_corpse()? 0 : 1 );
                inv -= ({ 0 });
                if( sizeof(inv) )
                        str += sprintf( obj->is_corpse() ? "%s�������У�\n%s\n" : "%s���ϴ����ţ�\n%s\n",
                                pro, implode(inv, "\n") );
        }
        if (!sizeof(inv) && me != obj && obj->query("race")=="����")
                str += pro + "����û���κδ�����\n";
        inv = all_inventory(obj);
        if( sizeof(inv) ) {
                inv = map_array(inv, "inventory_look", this_object(), 1, 1 );
                inv -= ({ 0 });
                if( sizeof(inv) )
                        str += sprintf( "%s����װ���ţ�\n%s\n",
                                pro, implode(inv, "\n") );
        }
        if (!sizeof(inv) && me != obj && obj->query("race")=="����")
                str += pro + "����û���κ�װ����\n";

        message("vision", str, me);

        if( obj!=me && obj->visible(me)
        &&      userp(me)
        &&      living(obj)
        &&      (int)obj->query("shen") < -(int)me->query_int() * 100 ) {
                write( obj->name() + "ͻȻת��ͷ������һ�ۡ�\n");
                COMBAT_D->auto_fight(obj, me, "berserk");
        }

        return 1;
}

string inventory_look(object obj, int flag, int equip)
{
        string str;

        reset_eval_cost();
        if( obj->query("equipped")) {
                if (!flag || (!equip && obj->query("armor_type"))
                || (equip && obj->query("weapon_prop")))
                    str = HIC "  ��" NOR + obj->short();
                else return 0;
        }
    else if( obj->query("embedded") && flag && !equip)  str = HIR "  ��" NOR + obj->short();
        else if( !flag )
                str = "    " + obj->short();
        else return 0;
        return str;
}


int look_room_item(object me, string arg)
{
        object env;
        mapping item, exits;

        if( !objectp(env = environment(me)) )
                return notify_fail("����ֻ�л����ɵ�һƬ��ʲôҲû�С�\n");
        if( mapp(item = env->query("item_desc")) && !undefinedp(item[arg]) ) {
                if( stringp(item[arg]) )
                        write(item[arg]);
                else if( functionp(item[arg]) )
                        write((string)(*item[arg])(me));

                return 1;
        }
        if( mapp(exits = env->query("exits")) && !undefinedp(exits[arg]) ) {
                if( objectp(env = load_object(exits[arg])) )
                        look_room(me, env, NATURE_D->is_night());
                else return notify_fail("��������޷����壬�뱨����ʦ��\n");
                return 1;
        }
        return notify_fail("��Ҫ��ʲô��\n");
}

string *tough_level_desc = ({
BLU"����һ��"NOR,BLU"��������"NOR,BLU"��֪����"NOR,BLU"��ѧէ��"NOR,BLU"����ǿǿ"NOR,
BLU"�����ž�"NOR,BLU"����é®"NOR,BLU"��֪һ��"NOR,BLU"����ͨͨ"NOR,BLU"ƽƽ����"NOR,

HIB"ƽ������"NOR,HIB"��ͨƤë"NOR,HIB"��������"NOR,HIB"������"NOR,HIB"����С��"NOR,
HIB"����С��"NOR,HIB"����Ѿ�"NOR,HIB"��������"NOR,HIB"��������"NOR,HIB"�ڻ��ͨ"NOR, 

CYN"�������"NOR,CYN"¯����"NOR,CYN"��Ȼ���"NOR,CYN"���д��"NOR,CYN"���д��"NOR,
CYN"��Ȼ��ͨ"NOR,CYN"�������"NOR,CYN"�޿�ƥ��"NOR,CYN"����Ⱥ��"NOR,CYN"����似"NOR,

HIC"�����뻯"NOR,HIC"��ͬ����"NOR,HIC"����Ⱥ��"NOR,HIC"�Ƿ��켫"NOR,HIC"�����ױ�"NOR,
HIC"��������"NOR,HIC"һ����ʦ"NOR,HIC"�������"NOR,HIC"�񹦸���"NOR,HIC"������˫"NOR,

HIR"��������"NOR,HIR"���춯��"NOR,HIR"������"NOR,HIR"������ʥ"NOR,HIR"�������"NOR,
HIR"��ǰ����"NOR,HIR"���˺�һ"NOR,HIR"��ز�¶"NOR,HIR"��ɨ����"NOR,HIR"��ɲ�"NOR,

HIY"�����ɵ�"NOR,HIY"��������"NOR,HIR"ǿ������"NOR,HIY"��������"NOR,HIR"ǰ�޹���"NOR,
HIY"��豹���"NOR,HIY"��������"NOR,HIY"���ž���"NOR,HIY"�����޵�"NOR,HIY"���µ�һ"NOR,
});
/*
BLU "����һ��" NOR,BLU "��������" NOR,BLU "����ҳ�" NOR,BLU "��ѧէ��" NOR,HIB "�����ž�" NOR,
HIB "��֪һ��" NOR,HIB "����ͨͨ" NOR,HIB "ƽƽ����" NOR,HIB "ƽ������" NOR,HIB "��ͨƤë" NOR,
HIB "��������" NOR,HIB "������" NOR,HIB "����С��" NOR,HIB "����С��" NOR,HIB "�������" NOR,
CYN "�������" NOR,CYN "��Ȼ���" NOR,CYN "���д��" NOR,CYN "���д��" NOR,CYN "��Ȼ��ͨ" NOR,
CYN "�������" NOR,CYN "�޿�ƥ��" NOR,CYN "����Ⱥ��" NOR,CYN "����似" NOR,CYN "�����뻯" NOR,
CYN "����Ⱥ��" NOR,HIC "�Ƿ��켫" NOR,HIC "��������" NOR,HIC "һ����ʦ" NOR,HIC "�񹦸���" NOR,
HIC "������˫" NOR,HIC "��������" NOR,HIC "������" NOR,HIC "��ز�¶" NOR,HIR "��ɲ�" NOR
*/

string tough_level(int power, int hide_level)
{
/*        int lvl, rawlvl;

        if(power<0) power=0;
        rawlvl = (int) pow( (float) 1.0 * power, 0.3);
        lvl = to_int(rawlvl);
        
        if(hide_level)
            lvl = hide_level;
        if( lvl >= sizeof(tough_level_desc) )
            lvl = sizeof(tough_level_desc)-1;
        
        return tough_level_desc[lvl];
*/
	int lvl;
	int rawlvl;
	int grade = 1;
	if(power<0) power=0;
	rawlvl = (int) pow( (float) 1.0 * power, 0.3);
	lvl = to_int(rawlvl/grade);
                        if( lvl >= sizeof(tough_level_desc) )
                                lvl = sizeof(tough_level_desc)-1;
                        return tough_level_desc[((int)lvl)];

}

string getdam(object obj)
{

        int level;
        string *heavy_level_desc= ({"����","����","����","����","����","����",});
        
        level = obj->query("jiali");
        if(obj->query_temp("apply/damage") > 0)
            level += obj->query_temp("apply/damage")/3;  // weapon ����Ч������ unarmed / 3
            
        level /= 30;
        if( level >= sizeof(heavy_level_desc) )
            level = sizeof(heavy_level_desc)-1;
        return heavy_level_desc[((int)level)];
}

int help (object me)
{
        write(@HELP
ָ���ʽ: look [<��Ʒ>|<����>|<����>]
 
���ָ������鿴�����ڵĻ�����ĳ����Ʒ��������Ƿ���
 
HELP
);
        return 1;
}

