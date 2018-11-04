#include <ansi.h>
inherit F_CLEAN_UP;

#define SCALE   (1.0/10.0)
#define STATUS  "ϵͳ�������д��"

string memory_expression(int m);

int count_ppls();

void create() { seteuid(getuid(this_object())); }

int main() {
        object *ob;
        object *o;
        float value;
        mapping r;

        r = rusage();
        value = SCALE * (r["utime"] + r["stime"]) / uptime();

        write(HIG"        .__________ ϵ ͳ �� Ѷ __________.\n"NOR);
        write(HIW"����������������������������������������������������\n");
        write(" Mud ��ʶ�����ƣ�  " + MUD_NAME + ".\n");
        write(" ����ϵͳ�İ汾��  " + __VERSION__ + "\n");
        write(" ϵͳ������汾��  H.Y.I.I Mudlib Ver 2.0\n");
        printf(" CPU ʹ�ðٷֱȣ�  %f %% ����� Mud ʹ����.\n", value );
        write(" CPU �ĸ���״����  " + query_load_average() + ".\n");
        printf(" ��ʹ�õļ����壺  %s bytes.\n", memory_expression(memory_info()) );
        write(" ����ʹ����������  " + sizeof( users() ) + "  ����������.\n");
        write(" ���������������  " + sizeof( livings() ) + "  ��������.\n");
        write(" ע��ʹ����������  " + count_ppls() + "  �������ڱ� Mud ע��.\n");
        write(" ��������������  " + sizeof( objects() ) + " �����.\n");
        write(" ����ִ�е�ʱ�䣺  " + CHINESE_D->chinese_period(uptime()) + "\n");
                        ob = filter_array( livings(),
                                (: $1->is_character() && !userp($1) && clonep($1) :) );
         printf(" ���� %d �� NPC �����\n", sizeof(ob));
                        o = filter_array( livings(),
                                (: $1->is_character() && !userp($1) && !query_heart_beat($1) && clonep($1):) );
         printf(" ���� %d �� NPC �����������\n", sizeof(o));
                         ob = objects( (: $1->is_fighting() :) );
                        o = filter_array( livings(),
                                (: $1->is_character() && userp($1) && !query_heart_beat($1) :) );
         printf(" ���� %d �� ��� ��������\n", sizeof(o));
                         ob = objects( (: $1->is_fighting() :) );

         printf(" ���� %d ����������ս��״̬��\n", sizeof(ob));
                        ob = objects( (: $1->is_killing() && $1->is_fighting() :) );
         printf(" ���� %d ���������������ಫ��ս��״̬��\n", sizeof(ob));
                        ob = objects( (: $1->is_killing() :) );
         printf(" ���� %d �����������������ﻥ���ޡ�\n", sizeof(ob));
                        ob = objects( (: query_heart_beat :) );
         printf(" ���� %d ������� heart beat Ϊ��Ч״̬��\n", sizeof(ob));
                        ob = objects( (: virtualp :) );
         printf(" ���� %d �����������\n", sizeof(ob));
                        ob = objects( (: function_exists("create_door", $1) :) );
         printf(" ���� %d �����䡡\n", sizeof(ob));
                        if( !find_object(ROOM) ) ROOM->foo();
                        ob = objects( (: inherits(ROOM, $1) :) );
         printf(" ���� %d ������̳б�׼���䡡\n", sizeof(ob));
                        if( !find_object(F_EQUIP) ) F_EQUIP->foo();
                        ob = objects( (: inherits(F_EQUIP, $1) :) );
         printf(" ���� %d ������̳б�׼װ����\n", sizeof(ob));
        write(HIG"����������������������������������������������������\n"NOR);        
        write(" Mud ���ڵ�״̬��  " + STATUS + ".\n");
        return 1;
}

string memory_expression(int m)
{
        float mem;

        mem = m;
        if( mem<1024 ) return m + "";
        if( mem<1024*1024 )

                return sprintf("%.2f K", (float)mem / 1024);
        return sprintf("%.3f M", (float)mem / (1024*1024));
}

int count_ppls()
{
        int count,i;
        string *dir, *ppls;

        seteuid(getuid());

        dir = get_dir(DATA_DIR + "login/");
        for(i=0; i<sizeof(dir); i++) {
        ppls = get_dir(DATA_DIR + "login/" + dir[i] + "/");
        count += sizeof(ppls);
        }
        return count;
}

int help() {

   write(@HELP
ָ���ʽ��mudinfo

���ָ�����ʾ�й���� Mud ��һЩϵͳ��Ѷ��

HELP
        );
         return 1;
}


