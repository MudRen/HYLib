// mudlist.c
// last modify by superken@WLZBII 1999

#include <ansi.h>
#include <net/daemons.h>
#include <net/macros.h>

inherit F_CLEAN_UP;
int main(object me,string arg)
{     
         mapping mud_list;
        mapping mud_svc;
        mixed *muds;
        string output;
        int loop, size, total,count=0;
    
        if( !find_object(DNS_MASTER) )
                return notify_fail("��·���鲢û�б����롣\n");

        //      Obtain mapping containing mud data
        mud_list = (mapping)DNS_MASTER->query_muds();
       // so we recognise ourselves as a DNS mud
        mud_svc = DNS_MASTER->query_svc() + ([ Mud_name() : 0 ]);

        if(!mud_list)
                return notify_fail( MUD_NAME + "Ŀǰ��û�и���·������ Mud ȡ����ϵ��\n");

        //      Get list of all mud names within name server
        muds = keys( mud_list ) - ({ "DEFAULT" });

        //      Place mudlist into alphabetical format
        muds = sort_array(muds, 1);
        //      If mudname provided, search server's database for a match
        //      and display its cooresponding address
        if( arg ) arg = lower_case(arg);
               
               if (arg == mud_list[arg]) arg="all";
               if(arg!="all"&&arg && arg!="") {
                       arg = htonn(arg);
               if(!mapp( mud_list[arg] )) {
                        write(MUD_NAME + "��û�к���� Mud ȡ����ϵ��\n");
                        return 1;
                }
                      
              printf("\n���й� %s �ĵ�ǰ���ϡ�\n"
                                "�ԩ�������������������������������������\n"
                                "���������ơ�"WHT"  %s\n"NOR
                                "�� ��  �� ��"WHT"  %s\n"NOR
                                "�� ��  �� ��"WHT"  %s\n"NOR
                                "�� MudOS  ��"WHT"  %s\n"NOR
                                "�� Mudlib ��"WHT"  %s\n"NOR
                                "�� ��  �� ��"WHT"  %s\n"NOR
                                "�� ��  �� ��"WHT"  %s\n"NOR
                                "�� ״  ̬ ��"WHT"  %s\n"NOR
                                "��������ҡ�"YEL"  %s\n"NOR
                                "������ʱ�䡻"WHT"  %s\n"NOR
                                "�ԩ�������������������������������������\n\n",
                                mud_list[arg]["NAME"],
                                undefinedp(mud_list[arg]["MUDNAME"])?
                                "����":mud_list[arg]["MUDNAME"],
                                undefinedp(mud_list[arg]["ENCODING"])?
                                "����":(mud_list[arg]["ENCODING"]=="GB"?"���庺��":"���庺��"),
                                undefinedp(mud_list[arg]["VERSION"])?
                                "����":mud_list[arg]["VERSION"],
                                undefinedp(mud_list[arg]["DRIVER"])?
                                "����":mud_list[arg]["DRIVER"],
                                undefinedp(mud_list[arg]["MUDLIB"])?
                                "����":mud_list[arg]["MUDLIB"],
                                mud_list[arg]["HOSTADDRESS"],
                                mud_list[arg]["PORT"],
                                mud_list[arg]["_dns_no_contact"]<1?
                                "����":"�Ͽ�",
                                undefinedp(mud_list[arg]["USERS"])?
                                "����":mud_list[arg]["USERS"],
                                undefinedp(mud_list[arg]["TIME"])?
                                "����":mud_list[arg]["TIME"],
                                );
                return 1;
        }
        output = 
YEL+"Mud                  ��������                ������·λַ     ����  ����\n"+NOR+
HIC+"��"HIY"��������������������������������������������������������������������"HIC"��\n"NOR;
        //      Loop through mud list and store one by one
        for(loop = 0, size = sizeof(muds); loop<size; loop++) {

                if( !arg && mud_list[muds[loop]]["VERSION"] != MUDLIB_VERSION )
                        continue;
                if( arg ) {
                     //   if( arg =="ES" && mud_list[muds[loop]]["MUDLIB"] != "Eastern Stories" )
                     //           continue;
                        if( arg =="" && mud_list[muds[loop]]["MUDLIB"] == MUDLIB_NAME )
                                continue;
                }               
                if( mud_list[muds[loop]]["_dns_no_contact"] > 0 ) {
                        if( !wizardp(me) || (wizardp(me) && me->query("env/debug")) )
                                continue;
                }

                count = loop;
                if( htonn(lower_case(muds[loop])) == htonn(lower_case(INTERMUD_MUD_NAME)) )
                    output +=  BBLU+HIW;
                else
                        output += NOR;
                        if( undefinedp(mud_list[muds[loop]]["MUDNAME"]) ) {
                        output +=  sprintf("%-43s  %-15s  %4s", 
                                lower_case(muds[loop]),
                                mud_list[muds[loop]]["HOSTADDRESS"],
                                mud_list[muds[loop]]["PORT"]);
                }
                else {
                        output +=  sprintf("%-20s %-23s %-15s  %4s", 
                                lower_case(muds[loop]),
                                undefinedp(mud_list[muds[loop]]["MUDNAME"])?
                                "":mud_list[muds[loop]]["MUDNAME"],
                                mud_list[muds[loop]]["HOSTADDRESS"],
                                mud_list[muds[loop]]["PORT"]);
                }
                if(!undefinedp(mud_list[muds[loop]]["USERS"]))
                                output+=sprintf("  %-4s", mud_list[muds[loop]]["USERS"] );
                else
                                output+=sprintf("  ����", mud_list[muds[loop]]["USERS"] );

                output +=NOR"\n";
                total ++;
        }
        //      Display dumped mudlist output through user's more pager
output+=HIC"��"HIY"��������������������������������������������������������������������"HIC"��\n"NOR;
        output += sprintf("���� "HIG"%d"NOR" �� "YEL"Mud"NOR" ��"+MUD_NAME+"���ߡ�\n"NOR,total==0?0:total-1);
        this_player()->start_more( output );

        return 1;
}
int help()
{
        write("\nָ���ʽ��mudlist            �г�Ŀǰ���������е� Mud��\n"
                "          mudlist <Mud����>  �г�ָ�� Mud ����Ϣ��\n"
                "          mudlist all        �г�Ŀǰ���������е� Mud��\n\n"
        );
        return 1;
}

