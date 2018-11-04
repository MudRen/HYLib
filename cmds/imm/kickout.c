//  kickout.c
// by edward 

#include "/doc/help.h"
#include <ansi.h>

inherit F_CLEAN_UP;
inherit F_DBASE;

int main(object me, string arg)
{
        string name,q_name,q_id,q_ip;
        object obj;

        if( !arg ) return notify_fail("ָ���ʽ : kickout <�����>\n" );

        seteuid(ROOT_UID);

    obj = LOGIN_D->find_body(arg);
        if( !obj || !userp(obj) ) return notify_fail("û��������....��\n");

//        name = obj->short(1);
//        q_name = obj->name();
        q_id = obj->query("id");
        q_ip = query_ip_name(obj);

        if( me == obj )
                return notify_fail("�� quit ����ָ���Щ :) \n");

        if( (wiz_level(me) < wiz_level(obj)) || (wiz_level(me) == wiz_level(obj)) )
                return notify_fail("�㲻�ܸϼ������ߵ���ʦ�����ߣ�\n");

        tell_room( environment(obj), me->name() + "ͻȻ����������ǰ������˵������"+q_name +
                        "�������" + RANK_D->query_rude(obj) + "�����ɣ�\n" );
        obj->set("last_on", time());
        obj->save();
        catch(destruct(obj));
        if( obj )
                return notify_fail("���޷������������ߡ�\n");
        else {
                set("channel_id", me->name() );
        CHANNEL_D->do_channel(this_object(), "rumor", q_name + "��ϵͳ�߳���"+MUD_NAME+"��");
                CHANNEL_D->do_channel(this_object(), "sys", "�ҽ�"NOR + name + HIR"�߳���ϵͳ��");
                log_file("kickout",
                        sprintf("%s(%s) kickout %s(%s) on %s at %s.\n", me->name(), 
                        me->query("id"), q_name, q_id, q_ip, ctime(time()) ) );
        }
        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : kickout <�����>

���������ǿ�ȶ����������ߡ�

HELP );
        return 1;
}

