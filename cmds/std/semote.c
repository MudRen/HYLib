// semote.c

#include "/doc/help.h"

inherit F_CLEAN_UP;

int checksemote(object me,string arg);
int femote(object me,string arg);
int show(object me,string str,string arg,int count); 
int flag = 1;

int main(object me, string arg)
{
        string *e, out="";
        int i,j = 0;
	if( (int)me->query("jing") < 50 )
		return notify_fail("��ľ����޷����С�\n");
	if( !wizardp(me) )
		me->receive_damage("jing", 50);

        if (!arg)
        {
                e = sort_array(EMOTE_D->query_all_emote(), 1);

                for(i=0; i<sizeof(e); i++)
                {
                        out += sprintf("%-13s%s", e[i], (j++%6==5)?"\n": "");
                }
                me->start_more(out + "\n");
                return 1;
        }
        else
                return checksemote(me,arg);
}

int checksemote(object me, string arg)
{
        mapping emote;
        string str,*e;
        int i,count;
        count = 0;        
        emote = EMOTE_D->query_emote(arg);
        e = sort_array(EMOTE_D->query_all_emote(), 1);
        str="";
	if( (int)me->query("jing") < 50 )
		return notify_fail("��ľ����޷����С�\n");
	if( !wizardp(me) )
		me->receive_damage("jing", 50);

        if ( !arg )
        {
                for(i=0; i<sizeof(e); i++)
                {
                        str += sprintf("%s%s\n%s\n","Emote���ƣ�",e[i],EMOTE_D->query_emote(e[i])["others_target"] );
                }
        }
        else
        {
                for(i=0; i<sizeof(e); i++)
                {
                        if ( arg==e[i] )
                        {
                                str=sprintf("%s%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n","Emote���ƣ�",e[i],
                                emote["myself"], emote["others"], emote["myself_self"],
                                emote["others_self"], emote["myself_target"], emote["target"],
                                emote["others_target"] );
                                count ++;
                                break;
                        }
                        if (arg==e[i][0..sizeof(arg)-1])
                        {
                                str += sprintf("%s%s\n%s%s\n","Emote���ƣ�",e[i],"���ݣ�",EMOTE_D->query_emote(e[i])["others_target"] );
                                count ++;
                        }
                }
        } 
        if (str=="")
                return femote(me,arg);
        else
        {
                flag = 1;
                return show(me,str,arg,count);
        }
}

int femote(object me,string arg)
{
        mapping emote;
        string *e, *loop;
        string str="", msg;
        int i,count,k;
        count = 0;
	if( (int)me->query("jing") < 50 )
		return notify_fail("��ľ����޷����С�\n");
	if( !wizardp(me) )
		me->receive_damage("jing", 50);

        loop = ({ "others_target", "others_self", "others" });

        e = sort_array( EMOTE_D->query_all_emote(), 1);

        for(i=0; i<sizeof(e); i++)
        {
                emote = EMOTE_D->query_emote(e[i]);
                for( int j=0; j<sizeof(loop); j++ )
                {
                        msg = emote[ loop[j] ];
                        if( msg && strsrch(msg, arg) != -1 )
                        {
                                str += sprintf("Emote ��: %s\n����: %s\n", e[i], msg);
                                k ++;
                        }
                }
                if( k )
                        count ++;
                k = 0;
        }

        if(  str == "" )
                return notify_fail(MUD_NAME" ���޷��ϲ�ѯ����["+ arg +"]�� Emote.\n");
        else
        {
                flag = 0;
                return show(me,str,arg,count);
        }
}

int show(object me,string str,string arg,int count)
{
	if( (int)me->query("jing") < 50 )
		return notify_fail("��ľ����޷����С�\n");
	if( !wizardp(me) )
		me->receive_damage("jing", 50);

        str =
    		"\n����" + arg + "�Ĳ�ѯ�����"
                "\n---------------------------------------------------------------\n"
                + str;
        str = replace_string(str, "$n", "(�Է�)");
        str = replace_string(str, "$N", me->name(1));
        str = replace_string(str, "$P", "��");
        str = replace_string(str, "$p", "(��/��)");
        str = replace_string(str, "$S", RANK_D->query_self(me));
        str = replace_string(str, "$s", RANK_D->query_self_rude(me));
        str = replace_string(str, "$R", "(�Է��Ĵ�³�ƺ�");
        str = replace_string(str, "$r", "(�Է��Ĵ�³�ƺ�)");
        str = replace_string(str, "$C", "(�Լ����س�)");
        str = replace_string(str, "$c", "(�Է����س�)");

        str += "---------------------------------------------------------------\n";
        flag?str += sprintf("��%s�У���[%s]��ͷ�� Emote ���� %d ����\n",MUD_NAME, arg, count ):str += sprintf("��%s�У�����[%s]�� emote ���� %d ����\n",MUD_NAME, arg, count );
        me->start_more(str);
        return 1;
}

int help(object me)
{
  write(@HELP
ָ���ʽ : semote [��Ӣ��]

���ָ��Ӳ���ʱ�����г�Ŀǰ����ʹ�õ�Emote��
���ϲ����󣬿��������Բ���Ϊ��ͷ���иò�����Emote��

HELP
    );
    return 1;
}

